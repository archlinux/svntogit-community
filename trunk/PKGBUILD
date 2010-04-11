# Maintainer: Thorsten Töpper <atsutane-tu@freethoughts.de>

pkgname=i3-wm
_pkgname=i3
pkgver=3.e
pkgrel=1
pkgdesc="An improved dynamic tiling window manager"
arch=('i686' 'x86_64')
url="http://i3.zekjur.net/"
license=('BSD')
replaces=("i3")
groups=("i3")
depends=('libx11' 'xcb-util' 'libev' 'yajl')
makedepends=('bison' 'flex')
optdepends=('rxvt-unicode: The terminal emulator used in the default config.'
            'dmenu: As menu.')
options=('docs' '!strip')
source=(http://i3.zekjur.net/downloads/$_pkgname-$pkgver.tar.bz2)
md5sums=('28b70cc287e2c6607576171c3c6b3fdf')

build() {
  cd "$srcdir/$_pkgname-$pkgver"
  
  make || return 1
}

package() {
  cd "$srcdir/$_pkgname-$pkgver"
  make DESTDIR="$pkgdir/" install || return 1
  
  install -Dm644 man/i3.man \
    ${pkgdir}/usr/share/man/man1/i3.1 || return 1
  install -Dm644 man/i3-msg.man \
    ${pkgdir}/usr/share/man/man1/i3-msg.1 || return 1
  install -Dm644 man/i3-input.man \
    ${pkgdir}/usr/share/man/man1/i3-input.1 || return 1
  install -Dm644 LICENSE \
    ${pkgdir}/usr/share/licenses/${pkgname}/LICENSE || return 1
  
  #i3-wsbar will be provided by another package
  rm ${pkgdir}/usr/bin/i3-wsbar || return 1

  make clean
}

# vim:set ts=2 sw=2 et:
