# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Gordin <9ordin @t gmail dot com>

pkgname=lolcat
pkgver=100.0.1
pkgrel=1
pkgdesc='Okay, no unicorns. But rainbows!!'
url='https://github.com/busyloop/lolcat'
arch=('any')
license=('custom')
depends=('ruby' 'ruby-paint' 'ruby-optimist' 'ruby-manpages')
options=('!emptydirs')
source=(https://github.com/busyloop/lolcat/archive/v${pkgver}/${pkgname}-${pkgver}.tar.gz)
sha256sums=('3f4127e022a55cf201f167c57ffcffbb3ba3f2bd2cbd9dd6358de4208029ae08')
sha512sums=('23775e63e6265dc7fadc0849dffa79812c2a7e5ddd5301355e03a05388a64689cd6d830820852ae198cb719ab2161effb85d5c1a33f83d5d1c5cd8d8a774acb0')

prepare() {
  cd ${pkgname}-${pkgver}
  sed -r 's|~>|>=|g' -i lolcat.gemspec
  sed 's|git ls-files -- bin/\*|find bin -type f|' -i lolcat.gemspec
  sed 's|git ls-files -- {test,spec,features}/*|echo|' -i lolcat.gemspec
  sed 's|git ls-files|find -type f|' -i lolcat.gemspec
}

build() {
  cd ${pkgname}-${pkgver}
  gem build lolcat.gemspec
}

package() {
  cd ${pkgname}-${pkgver}
  local _gemdir="$(gem env gemdir)"
  gem install --ignore-dependencies --no-user-install -i "${pkgdir}${_gemdir}" \
    -n "${pkgdir}/usr/bin" ${pkgname}-${pkgver}.gem

  install -Dm 644 "${pkgdir}/${_gemdir}/gems/lolcat-${pkgver}/man/lolcat.6" \
    -t "${pkgdir}/usr/share/man/man6"
  install -Dm 644 LICENSE -t "${pkgdir}/usr/share/licenses/${pkgname}"
  install -Dm 644 README.md -t "${pkgdir}/usr/share/doc/${pkgname}"

  rm "${pkgdir}/${_gemdir}/cache/${pkgname}-${pkgver}.gem"
}

# vim: ts=2 sw=2 et:
