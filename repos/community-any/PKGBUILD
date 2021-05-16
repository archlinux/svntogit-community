# Maintainer: Tim Meusel <tim@bastelfreak.de>
# Contributor: Christian Rebischke <chris.rebischke@archlinux.org>

_gemname='hashdiff'
pkgname="ruby-${_gemname}"
pkgver=1.0.1
pkgrel=1
pkgdesc='Library to compute the smallest difference between two hashes'
arch=('any')
url="https://github.com/liufengyun/${_gemname}"
license=('MIT')
makedepends=('ruby-rdoc' 'ruby-bundler')
checkdepends=('ruby-rake' 'ruby-rspec')
depends=('ruby')
options=(!emptydirs)
source=("${url}/archive/v${pkgver}/${pkgname}-v${pkgver}.tar.gz")
sha512sums=('014e4eb6b84dd0266c7db4dd570be96df1c557ab16ccd060adbe2f464647032e58fd75d97ea05b452b773e4969665d59f08779e9d44562ea73ede8738f1e6219')

prepare() {
  cd "${srcdir}/${_gemname}-${pkgver}"

  # use `find` instead of `git`, since we have a tar ball and not a VCS repository
  sed --in-place 's/git ls-files.*`/find`/g' "${_gemname}.gemspec"
  sed --in-place '/test_files/d' "${_gemname}.gemspec"

  # rubocop would test if the code works on a legay ruby platform
  sed --in-place '/rubocop/d' Rakefile
  sed --in-place '/RuboCop/d' Rakefile

  # loading bundler isn't required and often triggers side effects
  # because it wants *all* gems from gemspec + Gemfile
  sed --in-place '/Bundler/d' Rakefile
  sed --in-place '/Bundler/d' Rakefile

  # the project has a few dependencies for releasing
  sed --in-place '/bluecloth/d' "${_gemname}.gemspec"
  sed --in-place '/rubocop/d' "${_gemname}.gemspec"
  sed --in-place '/yard/d' "${_gemname}.gemspec"
}

build() {
  cd "${srcdir}/${_gemname}-${pkgver}"
  gem build "${_gemname}.gemspec"
}

check() {
  cd "${srcdir}/${_gemname}-${pkgver}"
  rake spec
}

package() {
  cd "${srcdir}/${_gemname}-${pkgver}"
  local _gemdir="$(gem env gemdir)"
  gem install --verbose --ignore-dependencies --no-user-install --install-dir "${pkgdir}/${_gemdir}" --bindir "${pkgdir}/usr/bin" "${_gemname}-${pkgver}.gem"

  install -Dm 644 LICENSE -t "${pkgdir}/usr/share/licenses/${pkgname}/"

  rm -rf "${pkgdir}/${_gemdir}/cache"
}

# vim: ts=2 sw=2 et:
