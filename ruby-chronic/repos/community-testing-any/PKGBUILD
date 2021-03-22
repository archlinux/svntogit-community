# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>

_gemname=chronic
pkgname=ruby-${_gemname}
pkgver=0.10.2
pkgrel=3
pkgdesc='Natural language date/time parser written in pure Ruby'
url='https://github.com/mojombo/chronic'
arch=('any')
license=('MIT')
depends=('ruby')
makedepends=('ruby-rdoc' 'ruby-rake')
checkdepends=('ruby-minitest')
options=('!emptydirs')
source=(https://github.com/mojombo/chronic/archive/v${pkgver}/${pkgname}-${pkgver}.tar.gz)
sha256sums=('e7b01a3b4a512fbdafecc7a1cdc8dd102d1c3d9089ff32cf409f08d73204de0d')
sha512sums=('a8f9b12caf529374a163b13307208272e210d8d885a1bed47b64613dd319cc2cbbf2728c9a171f603bc2fe7a1383dd17b35f690b8597462fb329dbe4afe46c6e')

prepare() {
  cd ${_gemname}-${pkgver}
  sed -r 's|~>|>=|g' -i ${_gemname}.gemspec
  sed 's|git ls-files|find|' -i ${_gemname}.gemspec
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
  install -Dm 644 README.md HISTORY.md -t "${pkgdir}/usr/share/doc/${pkgname}"
  install -Dm 644 LICENSE -t "${pkgdir}/usr/share/licenses/${pkgname}"

  cd "${pkgdir}/${_gemdir}"
  rm "${pkgdir}/${_gemdir}/cache/${_gemname}-${pkgver}.gem"
  rm -r "${pkgdir}/${_gemdir}/gems/${_gemname}-${pkgver}/test"
}

# vim: ts=2 sw=2 et:
