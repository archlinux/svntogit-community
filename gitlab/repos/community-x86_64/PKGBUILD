# Maintainer: Anatol Pomozov <anatol.pomozov@gmail.com>
# Contributor: Sven-Hendrik Haase <svenstaro@gmail.com>
# Contributor: Pavol (Lopo) Hluchy <lopo AT losys DOT eu>
# Contributor: Jonas Heinrich <onny@project-insanity.org>
# Contributor: Massimiliano Torromeo <massimiliano.torromeo@gmail.com>
# Contributor: Tobias Hunger <tobias DOT hunger AT gmail DOT com>
# Contributor: Stefan Tatschner <stefan@sevenbyte.org>
# Contributor: Caleb Maclennan <caleb@alerque.com>

pkgname=gitlab
pkgver=15.5.0
pkgrel=1
pkgdesc="Project management and code hosting application"
arch=('x86_64')
url="https://gitlab.com/gitlab-org/gitlab-foss"
license=('MIT')
options=(!buildflags)
depends=('ruby2.7' 'git' 'gitlab-workhorse' 'gitlab-gitaly' 'openssh' 'redis' 'libxslt' 'icu' 're2' 'http-parser' 'nodejs' 'openssl')
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
        fixes.patch
        environment
        gitlab-puma.service
        gitlab-sidekiq.service
        gitlab-backup.service
        gitlab-mailroom.service
        gitlab-backup.timer
        gitlab.target
        gitlab.tmpfiles.d
        gitlab.logrotate)
install='gitlab.install'
sha512sums=('SKIP'
            'cd93f745f908800237034f639f1776e4d3111c4375d93e3d44be9b4b25f2e3a39ffaa43c70c3d32e1b534cbc968694288e742ff4052e5f2091cb74cf441170c6'
            '3eb5058d6edc2d16f5558a3ee485ba796aa64fb4b9eb7595390322344b809fcb47a45be9d7fe36c822ac2724aeecb2905a0ea9a868a56349ac2bc5c8c9f070e3'
            '5b1ca2958f03a5baf1c5576a1568072e8ed749e2d15745ecbcc4860d2dbd543f2f3ed077e8d87afac2670c9436b19fe498217b49916d56a4e31fb9811aeb9067'
            '451a030940f124bccd6d29c1924861b361d52db32cff6e745c144286c2afc7065e117f825721145ed2dd4406f5bcfa97e228a80b968aaa9a675613b71b776eba'
            '419848c668928276620b5229e457a39e0ed7e111f1da68a30c3e0ae1a644af1c869b004b35435ccec4ddcdf6cf7418b1ab71e6e2ee8a2c861c6625c8bfd908f6'
            'd86e16747ad79f514ce180646c68bec8b6fa61764b2b14b1621db998f48955c3fb81f4e19ecb0fbab9d603dd25d95929e6d72a473652608373e6551f26244738'
            'f8067d1ee444a50dc9b2ed871974225ad521c310eb191e075adb0e45e47168da7d16b92f2e40d7ce755041dd4426a05f0ad1385392b4db526aeaf8a638eb024f'
            'c76d634647336aaf157bc66ba094a363e971c0d275875a7df4521819147f54cd4c709eb8e024cdac9e900d99167e8a78a222587e7292e915573ef29060e6ec21'
            '879be339148123e32b58a5669fdd3d3bb8b5d711326cb618f95b1680a6ac3a83c85d8862f2691b352fa26c95e4764dbb827856e22a3e2b9e4a76c13fe42864b5'
            'abacbff0d7be918337a17b56481c84e6bf3eddd9551efe78ba9fb74337179e95c9b60f41c49f275e05074a4074a616be36fa208a48fc12d5b940f0554fbd89c3'
            '88e199d2f63e4f235930c35c6dfde80e6010e590907bd4de0af1fbfe6d5491ff56845aefcfe8edefa707712bd84fef96880655747b8bfb949ceeadc0456b0121')


_appdir="/usr/share/webapps/gitlab" # the app source code location
_etcdir="/etc/webapps/gitlab"
_datadir="/var/lib/gitlab" # directory with gitlab data and it also $HOME for 'gitlab' user
_logdir="/var/log/gitlab"

prepare() {
  cd gitlab-foss

  # GitLab tries to read its revision information from a file.
  git rev-parse --short HEAD > REVISION

  patch -p1 < ../fixes.patch
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
  bundle-2.7 lock --update=bundler-audit
  # 'lock' adds 'BUNDLED WITH' back. Remove it again.
  sed -e '/BUNDLED WITH/,+1d' -i Gemfile.lock
}

build() {
  cd gitlab-foss

  echo "Fetching bundled gems..."
  # Gems will be installed into vendor/bundle
  bundle-2.7 config build.gpgme --use-system-libraries  # See https://bugs.archlinux.org/task/63654
  bundle-2.7 config force_ruby_platform true # some native gems are not available for newer ruby
  bundle-2.7 install --jobs=$(nproc) --no-cache --deployment --without development test aws kerberos

  yarn install --production --pure-lockfile
  bundle-2.7 exec rake gettext:compile RAILS_ENV=production NODE_ENV=production USE_DB=false SKIP_STORAGE_VALIDATION=true NODE_OPTIONS="--max_old_space_size=3584"
  bundle-2.7 exec rake gitlab:assets:compile RAILS_ENV=production NODE_ENV=production USE_DB=false SKIP_STORAGE_VALIDATION=true NODE_OPTIONS="--max_old_space_size=3584"
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

  rm -r "${pkgdir}${_appdir}"/{.git,builds,tmp,log,shared}

  # Rails app hardcodes/configures by default that data is stored under $_appdir
  # Create symlinks that point to data directories under /var
  ln -fs "${_logdir}" "${pkgdir}${_appdir}/log"
  ln -fs "${_datadir}/builds" "${pkgdir}${_appdir}/builds"
  mkdir "${pkgdir}${_appdir}/tmp/"
  ln -fs "${_datadir}/backups" "${pkgdir}${_appdir}/tmp/backups"
  ln -fs "${_datadir}/uploads" "${pkgdir}${_appdir}/public/uploads"
  ln -fs "${_datadir}/shared" "${pkgdir}${_appdir}/shared"

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
