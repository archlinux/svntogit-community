# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Maintainer: Andreas 'Segaja' Schleifer <segaja at archlinux dot org>

_gemname=network_interface
pkgname=ruby-${_gemname}
pkgver=0.0.2
pkgrel=5
pkgdesc='Library to get network interface information'
url='https://github.com/rapid7/network_interface'
arch=('x86_64')
license=('MIT')
depends=('ruby')
makedepends=('ruby-rdoc')
options=('!emptydirs')
source=(${pkgname}-${pkgver}.tar.gz::https://github.com/rapid7/network_interface/archive/v${pkgver}.tar.gz)
sha512sums=('38174c4a1985ae82dc2459c21a7483a3cdbf6a0380814dc0b799a2bc250a3263fc8830d4127301041e7fc637dd6de45cd62214dd1a4d390b3acdb71cbae96d02')

prepare() {
  cd ${_gemname}-${pkgver}
  sed 's|git ls-files|find|' -i ${_gemname}.gemspec
}

build() {
  cd ${_gemname}-${pkgver}
  gem build ${_gemname}.gemspec
}

package() {
  cd ${_gemname}-${pkgver}
  local _gemdir="$(gem env gemdir)"
  gem install --ignore-dependencies --no-user-install -i "${pkgdir}/${_gemdir}" -n "${pkgdir}/usr/bin" ${_gemname}-${pkgver}.gem
  install -Dm 644 README.md -t "${pkgdir}/usr/share/doc/${pkgname}"
  install -Dm 644 LICENSE -t "${pkgdir}/usr/share/licenses/${pkgname}"
  find "${pkgdir}" \( -name gem_make.out -o -name mkmf.log \) -delete
  rm "${pkgdir}/${_gemdir}/cache/${_gemname}-${pkgver}.gem" \
    "${pkgdir}/${_gemdir}/gems/${_gemname}-${pkgver}/ext/network_interface_ext/Makefile"
  rm -rf "${pkgdir}/${_gemdir}/doc/${_gemname}-${pkgver}/ri/ext/"
}

# vim: ts=2 sw=2 et:
