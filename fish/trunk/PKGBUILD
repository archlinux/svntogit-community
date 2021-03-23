# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Bartłomiej Piotrowski <bpiotrowski@archlinux.org>
# Contributor: Kaiting Chen <kaitocracy@gmail.com>
# Contributor: Abhishek Dasgupta <abhidg@gmail.com>
# Contributor: Eric Belanger <eric@archlinux.org>
# Contributor: Jan Fader <jan.fader@web.de>

pkgname=fish
pkgver=3.2.1
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
sha256sums=('d8e49f4090d3778df17dd825e4a2a80192015682423cd9dd02b6675d65c3af5b'
            'SKIP')
sha512sums=('bf565bac93e7d163af5253b4053f9c9e760508b929624440fd8a160504a127c34013882576293c72a47ce7f285f87e0b594d61d7cebcefcc3be4e92c572926bc'
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
