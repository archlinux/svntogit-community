# Maintainer: Anatol Pomozov <anatol.pomozov@gmail.com>
# Contributor: Sven-Hendrik Haase <svenstaro@gmail.com>
# Contributor: Pavol (Lopo) Hluchy <lopo AT losys DOT eu>
# Contributor: Jonas Heinrich <onny@project-insanity.org>
# Contributor: Massimiliano Torromeo <massimiliano.torromeo@gmail.com>
# Contributor: Tobias Hunger <tobias DOT hunger AT gmail DOT com>
# Contributor: Stefan Tatschner <stefan@sevenbyte.org>
# Contributor: Caleb Maclennan <caleb@alerque.com>

pkgname=gitlab
pkgver=13.1.2
pkgrel=2
pkgdesc="Project management and code hosting application"
arch=('x86_64')
url="https://gitlab.com/gitlab-org/gitlab-foss"
license=('MIT')
options=(!buildflags)
depends=('ruby' 'ruby-bundler' 'git' 'gitlab-workhorse' 'gitlab-gitaly' 'openssh' 'redis' 'libxslt' 'icu' 're2' 'http-parser' 'nodejs' 'openssl')
makedepends=('cmake' 'postgresql' 'yarn' 'go' 'nodejs')
optdepends=('postgresql: database backend'
            'python-docutils: reStructuredText markup language support'
            'smtp-server: mail server in order to receive mail notifications')
backup=("etc/webapps/gitlab/database.yml"
        "etc/webapps/gitlab/gitlab.yml"
        "etc/webapps/gitlab/resque.yml"
        "etc/webapps/gitlab/puma.rb"
        "etc/webapps/gitlab/smtp_settings.rb"
        "etc/logrotate.d/gitlab")
source=(git+https://gitlab.com/gitlab-org/gitlab-foss.git#tag=v$pkgver
        configs.patch
        build_fix.patch
        environment
        gitlab-puma.service
        gitlab-sidekiq.service
        gitlab-backup.service
        gitlab-mailroom.service
        gitlab-backup.timer
        gitlab.target
        gitlab.tmpfiles.d
        gitlab.logrotate
        ruby27-pop-extra-arg.patch)
install='gitlab.install'
sha512sums=('SKIP'
            '19c69797d268216e254f82dd9e865a70c8e79039a34b09efba42542b6e59e4d74f546be566ad923f39ed9e873273b7341619efa71ce7689d97e1a72df5677753'
            '9623de113358d3d6e49047f688e272d9394579734ace1bd647497e8717a90784546d27e547a29197a16c80d72ad9f2c79eb65f8edc631deadf2ec90ee86ea44b'
            '5b1ca2958f03a5baf1c5576a1568072e8ed749e2d15745ecbcc4860d2dbd543f2f3ed077e8d87afac2670c9436b19fe498217b49916d56a4e31fb9811aeb9067'
            '75bf9e5ad238a862dfc2638101fb74101227d88958a5f0fdf1ced3833e403f91b6a5908dfb97c5172f75748737212bf87d05b7d39bbe90ed5d3a6c248c1c1ab6'
            '18f4a31935d0626c26d1be1942b715128cf3edcb114f672af16e4a145d8ac693e1afc7d59094cae3702e47e4c6c4cb4a62a009bafcbec500e69120a2dd400a2a'
            '8afffb8caafdaa7a39991a4e694efc5133af1dc201ae07f3dc3989dbabb983339941011ffdd1f97c63033c94a02a3a7a6eb3722001aa3e7155c16f6743aec4c8'
            '35c1175ef4347d700e2331c3963ac871cada50c9274964eb4ac8cb80bb27a7d3459bed1548bd1f3a1681b6eb5dd94fe7ec4855cab7b33dddc4e524a91ca791d7'
            'c76d634647336aaf157bc66ba094a363e971c0d275875a7df4521819147f54cd4c709eb8e024cdac9e900d99167e8a78a222587e7292e915573ef29060e6ec21'
            '879be339148123e32b58a5669fdd3d3bb8b5d711326cb618f95b1680a6ac3a83c85d8862f2691b352fa26c95e4764dbb827856e22a3e2b9e4a76c13fe42864b5'
            'abacbff0d7be918337a17b56481c84e6bf3eddd9551efe78ba9fb74337179e95c9b60f41c49f275e05074a4074a616be36fa208a48fc12d5b940f0554fbd89c3'
            '88e199d2f63e4f235930c35c6dfde80e6010e590907bd4de0af1fbfe6d5491ff56845aefcfe8edefa707712bd84fef96880655747b8bfb949ceeadc0456b0121'
            '0cc5c1df3cd18978df9a01bb64680d3a375c1ff4de6a453045dd26355777b4f08e3a05f55f035c8012a9683100de0bc3d11c280debcb343eb7167fc25342d5c0')


_appdir="/usr/share/webapps/gitlab" # the app source code location
_etcdir="/etc/webapps/gitlab"
_datadir="/var/lib/gitlab" # directory with gitlab data and it also $HOME for 'gitlab' user
_logdir="/var/log/gitlab"

prepare() {
  cd gitlab-foss

  # GitLab tries to read its revision information from a file.
  git rev-parse --short HEAD > REVISION

  patch -p1 < ../build_fix.patch
  patch -p1 < ../configs.patch
  # '/home/git' path in the config files indicates a default path that need to be adjusted
  grep -FqR '/home/git' config || exit 1

  cp config/gitlab.yml.example config/gitlab.yml
  cp config/database.yml.postgresql config/database.yml
  cp config/puma.rb.example config/puma.rb
  cp config/resque.yml.example config/resque.yml
  cp config/initializers/smtp_settings.rb.sample config/initializers/smtp_settings.rb

  echo "Setting up systemd service files ..."
  for service_file in gitlab-sidekiq.service gitlab-puma.service gitlab.logrotate gitlab-backup.service gitlab-mailroom.service; do
    sed -i "s|<DATADIR>|${_datadir}|g" "${srcdir}/${service_file}"
    sed -i "s|<APPDIR>|${_appdir}|g" "${srcdir}/${service_file}"
    sed -i "s|<LOGDIR>|${_logdir}|g" "${srcdir}/${service_file}"
  done

  # https://github.com/bundler/bundler/issues/6882
  sed -e '/BUNDLED WITH/,+1d' -i Gemfile.lock
  bundle lock --update=bundler-audit
  # 'lock' adds 'BUNDLED WITH' back. Remove it again.
  sed -e '/BUNDLED WITH/,+1d' -i Gemfile.lock
}

build() {
  cd gitlab-foss

  echo "Fetching bundled gems..."
  # Gems will be installed into vendor/bundle
  bundle config build.gpgme --use-system-libraries  # See https://bugs.archlinux.org/task/63654
  bundle config force_ruby_platform true # some native gems are not available for newer ruby
  bundle install --jobs=$(nproc) --no-cache --deployment --without development test aws kerberos

  # workaround for a ruby2.7 issue
  # https://gitlab.com/groups/gitlab-org/-/epics/2380
  # https://github.com/ruby-grape/grape/issues/1967
  pushd vendor/bundle/ruby/2.7.0/gems/grape-1.1.0/
  patch -p1 < $srcdir/ruby27-pop-extra-arg.patch
  popd

  yarn install --production --pure-lockfile
  bundle exec rake gitlab:assets:compile RAILS_ENV=production NODE_ENV=production NODE_OPTIONS="--max_old_space_size=4096"
  bundle exec rake gettext:compile RAILS_ENV=production
}

package() {
  depends+=('gitlab-shell')

  cd gitlab-foss

  install -d "${pkgdir}/usr/share/webapps"

  cp -r "${srcdir}"/gitlab-foss "${pkgdir}${_appdir}"
  # Remove unneeded directories: node_modules is only needed during build
  rm -r "${pkgdir}${_appdir}/node_modules"
  # https://gitlab.com/gitlab-org/omnibus-gitlab/blob/194cf8f12e51c26980c09de6388bbd08409e1209/config/software/gitlab-rails.rb#L179
  for dir in spec qa rubocop app/assets vendor/assets; do
    rm -r "${pkgdir}${_appdir}/${dir}"
  done

  chown -R root:root "${pkgdir}${_appdir}"
  chmod 755 "${pkgdir}${_appdir}"

  install -dm750 -o 105 -g 105 "${pkgdir}${_datadir}"
  install -dm750 -o 105 -g 105 "${pkgdir}${_datadir}/satellites"
  install -dm750 -o 105 -g 105 "${pkgdir}${_datadir}/shared/"{,artifacts,lfs-objects}
  install -dm750 -o 105 -g 105 "${pkgdir}${_datadir}/builds"
  install -dm700 -o 105 -g 105 "${pkgdir}${_datadir}/uploads"
  install -dm750 -o 105 -g 105 "${pkgdir}${_datadir}/backups"
  install -dm755 -o 105 -g 105 "${pkgdir}${_etcdir}"
  install -dm755 -o 105 -g 105 "${pkgdir}${_logdir}"
  install -dm755 "${pkgdir}/usr/share/doc/gitlab"

  rm -r "${pkgdir}${_appdir}"/{.git,builds,tmp,log}

  # TODO: Rails uses log dir under the rails root. Figure out if it is possible to configure rails
  # to log right to /var/log/gitlab
  ln -fs "${_logdir}" "${pkgdir}${_appdir}/log"

  # public/uploads is used by Pages
  ln -fs "${_datadir}/uploads" "${pkgdir}${_appdir}/public/uploads"

  # TODO: workhorse and shell secret files are the application data and should be stored under /var/lib/gitlab
  ln -fs "${_etcdir}/gitlab_workhorse_secret" "${pkgdir}${_appdir}/.gitlab_workhorse_secret"
  ln -fs /etc/webapps/gitlab-shell/secret "${pkgdir}${_appdir}/.gitlab_shell_secret"

  # Install config files
  for config_file in gitlab.yml database.yml puma.rb resque.yml; do
    mv "config/${config_file}" "${pkgdir}${_etcdir}/"
    # TODO: configure rails app to use configs right from /etc
    ln -fs "${_etcdir}/${config_file}" "${pkgdir}${_appdir}/config/"
  done
  mv "config/initializers/smtp_settings.rb" "${pkgdir}${_etcdir}/"
  ln -fs "${_etcdir}/smtp_settings.rb" "${pkgdir}${_appdir}/config/initializers/smtp_settings.rb"

  # Install secrets symlink
  # TODO: ruby uses _appdir to load config files. Figure out if we can load files directly from /etc
  ln -fs "${_etcdir}/secrets.yml" "${pkgdir}${_appdir}/config/secrets.yml"

  # files with passwords/secrets are set world-unreadable
  for secret_file in smtp_settings.rb; do
    chmod 660 "${pkgdir}${_etcdir}/${secret_file}"
    # TODO: should we just leave the secret files root owned?
    chown root:105 "${pkgdir}${_etcdir}/${secret_file}"
  done

  install -Dm644 "${srcdir}/environment" "${pkgdir}${_appdir}"

  # Install license and help files
  mv README.md MAINTENANCE.md CONTRIBUTING.md CHANGELOG.md PROCESS.md VERSION config/*.{example,postgresql} "${pkgdir}/usr/share/doc/gitlab"
  install -Dm644 "LICENSE" "${pkgdir}/usr/share/licenses/gitlab/LICENSE"

  # TODO: structure.sql looks more like an application data and should be stored under /var/lib/gitlab
  chown 105:105 "${pkgdir}${_appdir}/db/structure.sql"

  # Install systemd service files
  for service_file in gitlab-puma.service gitlab-sidekiq.service gitlab-backup.service gitlab-backup.timer gitlab.target gitlab-mailroom.service; do
    install -Dm644 "${srcdir}/${service_file}" "${pkgdir}/usr/lib/systemd/system/${service_file}"
  done

  install -Dm644 "${srcdir}/gitlab.tmpfiles.d" "${pkgdir}/usr/lib/tmpfiles.d/gitlab.conf"
  install -Dm644 "${srcdir}/gitlab.logrotate" "${pkgdir}/etc/logrotate.d/gitlab"
}
