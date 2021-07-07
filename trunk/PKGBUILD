# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Bartłomiej Piotrowski <bpiotrowski@archlinux.org>
# Contributor: Kaiting Chen <kaitocracy@gmail.com>
# Contributor: Abhishek Dasgupta <abhidg@gmail.com>
# Contributor: Eric Belanger <eric@archlinux.org>
# Contributor: Jan Fader <jan.fader@web.de>

pkgname=fish
pkgver=3.3.0
pkgrel=1
pkgdesc='Smart and user friendly shell intended mostly for interactive use'
url='https://fishshell.com/'
arch=('x86_64')
license=('GPL2')
depends=('glibc' 'gcc-libs' 'ncurses' 'pcre2')
optdepends=('python: man page completion parser / web config tool'
            'pkgfile: command-not-found hook')
makedepends=('cmake' 'python-sphinx')
checkdepends=('expect' 'procps-ng')
install=fish.install
backup=(etc/fish/config.fish)
source=(https://github.com/fish-shell/fish-shell/releases/download/${pkgver}/${pkgname}-${pkgver}.tar.xz{,.asc})
validpgpkeys=(003837986104878835FA516D7A67D962D88A709A) # David Adam <zanchey@gmail.com>
sha256sums=('a4215e4cab2a5b101b0b8843720bda3c7eb98e8a14dca0950b8ef17e94282faa'
            'SKIP')
sha512sums=('dd2288e93e5da9e34c6dcb4cb9accc164cb2b244d99e0b8df1f141789ba7e12b533cd2dc221bc42b96e1329daaba7f03b98e2f6111c558a887edb7047e8990cb'
            'SKIP')

build() {
  cd ${pkgname}-${pkgver}
  export CXXFLAGS+=" ${CPPFLAGS}"
  cmake \
    -B build \
    -DCMAKE_INSTALL_PREFIX=/usr \
    -DCMAKE_INSTALL_SYSCONFDIR=/etc \
    -DCMAKE_BUILD_TYPE=None \
    -DBUILD_DOCS=True \
    -Wno-dev
  make -C build VERBOSE=1
}

check() {
  cd ${pkgname}-${pkgver}
  make -C build test
}

package() {
  cd ${pkgname}-${pkgver}
  make -C build DESTDIR="${pkgdir}" install
}

# vim: ts=2 sw=2 et:
