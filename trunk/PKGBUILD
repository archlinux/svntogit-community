# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Maintainer: Andreas 'Segaja' Schleifer <segaja at archlinux dot org>
# Contributor: Dmitry Kharitonov <darksab0r@gmail.com>
# Contributor: Anatol Pomozov <anatol.pomozov@gmail.com>
# Contributor: eagletmt <eagletmt@gmail.com>

_gemname='mini_portile2'
pkgname="ruby-${_gemname}"
pkgver=2.8.0
pkgrel=1
pkgdesc='Simple autoconf builder for developers'
url='https://github.com/flavorjones/mini_portile'
arch=('any')
license=('MIT')
depends=('ruby')
makedepends=('ruby-rdoc')
options=('!emptydirs')
source=("https://github.com/flavorjones/mini_portile/archive/v${pkgver}/${pkgname}-${pkgver}.tar.gz")
sha256sums=('33285113315568cbd67659a09b0c596f061517a20bd5c33676810ed02836c2cd')
sha512sums=('c30d9387ee206dc1ef52b779a1e66e3c8a4247bea94009741911246371a74aebbe27c6f92cacc4a74c064fdaac3cec8e926232467377ad5c0fe501629e623b10')

prepare() {
  cd "mini_portile-${pkgver}"

  sed -r 's|~>|>=|g' -i "${_gemname}.gemspec"
  sed 's|git ls-files -z|find -type f -print0|' -i "${_gemname}.gemspec"
}

build() {
  cd "mini_portile-${pkgver}"

  gem build "${_gemname}.gemspec"
}

package() {
  cd "mini_portile-${pkgver}"

  local _gemdir="$(gem env gemdir)"

  gem install --ignore-dependencies --no-user-install -i "${pkgdir}${_gemdir}" -n "${pkgdir}/usr/bin" "${_gemname}-${pkgver}.gem"

  rm "${pkgdir}/${_gemdir}/cache/${_gemname}-${pkgver}.gem"

  install -Dm 644 LICENSE.txt -t "${pkgdir}/usr/share/licenses/${pkgname}"
  install -Dm 644 README.md CHANGELOG.md -t "${pkgdir}/usr/share/doc/${pkgname}"
}

# vim: ts=2 sw=2 et:
