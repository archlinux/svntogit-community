# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>

_gemname=minitest-global_expectations
pkgname=ruby-${_gemname}
pkgver=1.0.1
pkgrel=3
pkgdesc='Support minitest expectation methods for all objects'
url='https://github.com/jeremyevans/minitest-global_expectations'
arch=('any')
license=('MIT')
depends=('ruby' 'ruby-minitest')
makedepends=('ruby-rdoc' 'ruby-rake' 'ruby-bundler')
options=('!emptydirs')
source=(${url}/archive/${pkgver}/${pkgname}-${pkgver}.tar.gz)
sha512sums=('0ff4b0a1015a1b7b8cbf792da8874ee0a9af83c0e1d8771fc38fabe56f9d742203dd4330cab08111d8d9ecc6ee592f0dc059b11b240b85133256e8abec8c316f')
b2sums=('c08b1f899c41cf606488fa9484241c97231b89be94ffd9f10cab1d8cbe4aa234bc4a6cfed39ef3ddccca4b481df73c08d04cd8d72fdd20d9a05bd7f1eda8c1f5')

build() {
  cd ${_gemname}-${pkgver}
  sed -r 's|~>|>=|g' -i ${_gemname}.gemspec Rakefile
  rake package
}

check() {
  cd ${_gemname}-${pkgver}
  rake test
}

package() {
  cd ${_gemname}-${pkgver}
  local _gemdir="$(gem env gemdir)"
  gem install --ignore-dependencies --no-user-install -i "${pkgdir}${_gemdir}" \
    -n "${pkgdir}/usr/bin" ${_gemname}-${pkgver}.gem

  install -Dm 644 README.rdoc CHANGELOG -t "${pkgdir}/usr/share/doc/${pkgname}"
  install -Dm 644 MIT-LICENSE -t "${pkgdir}/usr/share/licenses/${pkgname}"

  rm -r "${pkgdir}/${_gemdir}/"{cache,gems/${_gemname}-${pkgver}/test}
}

# vim: ts=2 sw=2 et:
