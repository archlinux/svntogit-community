# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>

_gemname=kramdown
pkgname=ruby-kramdown
pkgver=2.3.1
pkgrel=2
pkgdesc='Fast, pure Ruby Markdown superset converter, using a strict syntax definition'
url='https://kramdown.gettalong.org/'
arch=('any')
license=('MIT')
depends=('ruby' 'ruby-rexml')
makedepends=('ruby-rdoc' 'ruby-rake')
options=('!emptydirs')
source=(${pkgname}-${pkgver}.tar.gz::https://github.com/gettalong/kramdown/archive/REL_${pkgver//./_}.tar.gz)
sha256sums=('9bc1a2ffb99c6f173027faf6905a348be9f1c28754ea6542d1b966db6fdcc30f')
sha512sums=('ebc5552891190d2daad290010022ae87d120415c4e19b7a352cf9aed411c36e32f558444967026fff83dc4624177acc86b8e6bbe9d7642f1194c40696377537a')

prepare() {
  cd ${_gemname}-REL_${pkgver//./_}
  rake gemspec
  sed -r 's|~>|>=|g' -i ${_gemname}.gemspec
}

build() {
  cd ${_gemname}-REL_${pkgver//./_}
  gem build ${_gemname}.gemspec
}

package() {
  cd ${_gemname}-REL_${pkgver//./_}
  local _gemdir="$(gem env gemdir)"
  gem install --ignore-dependencies --no-user-install -i "${pkgdir}${_gemdir}" -n "${pkgdir}/usr/bin" ${_gemname}-${pkgver}.gem
  install -Dm 644 README.md -t "${pkgdir}/usr/share/doc/${pkgname}"
  install -Dm 644 COPYING -t "${pkgdir}/usr/share/licenses/${pkgname}"
  install -d "${pkgdir}/usr/share/man/man1"
  mv "${pkgdir}/${_gemdir}/gems/kramdown-${pkgver}/man/man1/kramdown.1" "${pkgdir}/usr/share/man/man1"
  rm "${pkgdir}/${_gemdir}/cache/${_gemname}-${pkgver}.gem"
  rm -r "${pkgdir}/${_gemdir}/gems/kramdown-${pkgver}/test"
}

# vim: ts=2 sw=2 et:
