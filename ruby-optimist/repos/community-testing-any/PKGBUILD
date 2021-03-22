# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>

_gemname=optimist
pkgname=ruby-${_gemname}
pkgver=3.0.1
pkgrel=2
pkgdesc='Commandline option parser for Ruby that just gets out of your way'
url='https://github.com/ManageIQ/optimist'
arch=('any')
license=('MIT')
depends=('ruby')
makedepends=('ruby-rdoc' 'ruby-rake' 'ruby-bundler')
checkdepends=('ruby-minitest' 'ruby-chronic')
options=('!emptydirs')
source=(https://github.com/ManageIQ/optimist/archive/v${pkgver}/${pkgname}-${pkgver}.tar.gz)
sha512sums=('bb91d7bfde9fa58de0c0050ec7edd3d5e4f19ffe07339b1562aa31af96b98d6b60644f727ba9f49489b520b135d473f1d99fc7fffa96d4dc9b50b1103c778ef5')
b2sums=('91510cfca18ddc3c64d5ab0666374e9eaa033e350dd34a8e63fd375f0e1641e496a48746558ad4b0417965b0208ca9f555befcd7adc848910a13f0e98cfae6c8')

prepare() {
  cd ${_gemname}-${pkgver}
  sed -r 's|~>|>=|g' -i ${_gemname}.gemspec
  sed 's|git ls-files -z|find -print0|' -i ${_gemname}.gemspec
}

build() {
  cd ${_gemname}-${pkgver}
  gem build ${_gemname}.gemspec
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
  install -Dm 644 README.md History.txt -t "${pkgdir}/usr/share/doc/${pkgname}"
  install -Dm 644 README.md -t "${pkgdir}/usr/share/licenses/${pkgname}"

  cd "${pkgdir}/${_gemdir}"
  rm "${pkgdir}/${_gemdir}/cache/${_gemname}-${pkgver}.gem"
  rm -r "${pkgdir}/${_gemdir}/gems/${_gemname}-${pkgver}/test"
}

# vim: ts=2 sw=2 et:
