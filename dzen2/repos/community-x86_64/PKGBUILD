# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>
# Contributor: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Contributor: Mark Taylor <skymt0@gmail.com>

pkgname=dzen2
pkgver=0.9.5.14.488ab66
_commit=488ab66019f475e35e067646621827c18a879ba1
pkgrel=2
pkgdesc='General purpose messaging, notification and menuing program for X11'
url='https://github.com/robm/dzen'
arch=('x86_64')
license=('MIT')
depends=('libx11' 'libxpm' 'libxinerama' 'libxft')
makedepends=('git')
source=(${pkgname}::"git+https://github.com/robm/dzen#commit=${_commit}")
sha512sums=('SKIP')

pkgver() {
  cd ${pkgname}
  printf "%s.%s.%s" "$(grep 'VERSION = ' config.mk|cut -d' ' -f3|cut -d- -f1)" \
    "$(git rev-list --count HEAD)" "$(git rev-parse --short HEAD)"
}

prepare() {
  cd ${pkgname}
  sed -i 's|DZEN_XMP|DZEN_XPM|g' main.c

  CFLAGS="${CFLAGS} -Wall -Os \${INCS} -DVERSION=\\\"\${VERSION}\\\" -DDZEN_XINERAMA -DDZEN_XPM -DDZEN_XFT `pkg-config --cflags xft`"
  LIBS=" -L/usr/lib -lc -lXft -lXpm -lXinerama -lX11"

  echo "CFLAGS=${CFLAGS}" >> config.mk
  echo "LIBS=${LIBS}" >> config.mk
  echo "LDFLAGS=${LDFLAGS} ${LIBS}" >> config.mk
}

build() {
  cd ${pkgname}
  make X11INC=/usr/include X11LIB=/usr/lib
  make -C gadgets X11INC=/usr/include X11LIB=/usr/lib
}

package() {
  cd ${pkgname}
  make PREFIX=/usr MANPREFIX=/usr/man DESTDIR="${pkgdir}" install
  make -C gadgets PREFIX=/usr MANPREFIX=/usr/man DESTDIR="${pkgdir}" install
  install -Dm 644 LICENSE -t "${pkgdir}/usr/share/licenses/${pkgname}"
  install -Dm 644 README* -t "${pkgdir}/usr/share/doc/${pkgname}"
}

# vim: ts=2 sw=2 et:
