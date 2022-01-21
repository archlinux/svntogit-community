# Maintainer: Andreas 'Segaja' Schleifer <segaja at archlinux dot org>

_gemname='crass'
pkgname="ruby-${_gemname}"
pkgver=1.0.6
pkgrel=2
pkgdesc='Crass is a pure Ruby CSS parser based on the CSS Syntax Level 3 spec'
arch=('any')
url='https://github.com/rgrove/crass'
license=('MIT')
options=(!emptydirs)
depends=('ruby')
makedepends=('ruby-bundler' 'ruby-rake')
checkdepends=('ruby-minitest')
source=("${url}/archive/v${pkgver}/${pkgname}-${pkgver}.tar.gz")
sha512sums=('de98dea48d0cff148b3000d7388256552d1bf5a014ecbc074efc909473bc6edf2cf1db36179aaa4284eb810618dafc346757ac61708c9659045e013e6c6d4e36')

prepare() {
  cd "${_gemname}-${pkgver}"

  # we built based on a tar archive, not a git repo
  sed --in-place 's/git ls-files -z/find -print0/' "${_gemname}.gemspec"

  # update gemspec/Gemfile to allow newer version of the dependencies
  sed --in-place --regexp-extended 's|~>|>=|g' "${_gemname}.gemspec"
}

build() {
  cd "${_gemname}-${pkgver}"

  rake build
}

check() {
  cd "${_gemname}-${pkgver}"

  rake test
}

package() {
  cd "${_gemname}-${pkgver}"

  local _gemdir="$(gem env gemdir)"

  gem install --ignore-dependencies --no-user-install -i "${pkgdir}/${_gemdir}" -n "${pkgdir}/usr/bin" "pkg/${_gemname}-${pkgver}.gem"

  rm "${pkgdir}/${_gemdir}/cache/${_gemname}-${pkgver}.gem"

  install -Dm 644 LICENSE "${pkgdir}/usr/share/licenses/${pkgname}/LICENSE"
  install -Dm 644 HISTORY.md README.md --target-directory "${pkgdir}/usr/share/doc/${pkgname}"
}
