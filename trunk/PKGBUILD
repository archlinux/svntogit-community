# $Id$
# Maintainer: Sergej Pupykin <pupykin.s+arch@gmail.com>
# Maintainer: BlackIkeEagle <ike DOT devolder AT gmail DOT com>
# Contributor: Valeriy Lyasotskiy <onestep@ukr.net>
# Contributor: Jan Willemson <janwil@hot.ee>
# Contributor: Hugo Ideler <hugoideler@dse.nl>
# Original PKGBUILD: Andre Naumann <anaumann@SPARCed.org>
# See http://bbs.archlinux.org/viewtopic.php?t=9318&highlight=fpc

pkgname=fpc
pkgver=3.0.4
pkgrel=4
pkgdesc="Free Pascal Compiler, Turbo Pascal 7.0 and Delphi compatible."
arch=('x86_64')
url="http://www.freepascal.org/"
license=('GPL' 'LGPL' 'custom')
backup=("etc/fpc.cfg")
depends=('ncurses' 'zlib' 'expat' 'binutils' 'make')
makedepends=(fpc)
options=(zipman staticlibs)
source=(ftp://ftp.freepascal.org/pub/fpc/dist/$pkgver/source/fpcbuild-$pkgver.tar.gz)
sha256sums=('f66514e6f2c2e4e1bccccb4d554c24b77682ed61c87811ae5dd210f421855e76')

build() {
  cd "$srcdir"/fpcbuild-$pkgver
  pushd fpcsrc/compiler
  fpcmake -Tall
  popd
  make build NOGDB=1
}

package() {
  cd "$srcdir"/fpcbuild-$pkgver

  export HOME="$srcdir"

  make -j1 PREFIX="$pkgdir"/usr install NOGDB=1

  export PATH="$pkgdir"/usr/bin:$PATH

  install -Dm0644 fpcsrc/rtl/COPYING.FPC "$pkgdir"/usr/share/licenses/${pkgname}/COPYING.FPC

  [ "$CARCH" = "x86_64" ] && ln -s /usr/lib/fpc/${pkgver}/ppcx64 "$pkgdir"/usr/bin/

  mkdir -p "$pkgdir"/etc
  "$pkgdir"/usr/lib/fpc/${pkgver}/samplecfg "$pkgdir"/usr/lib/fpc/${pkgver} "$pkgdir"/etc

  # use -fPIC by default
  echo -e "#ifdef cpux86_64\n# for x86_64 use -fPIC by default\n-Cg\n#endif" >> "$pkgdir/etc/fpc.cfg"

  mv "$pkgdir"/usr/man "$pkgdir"/usr/share/

  find "$pkgdir"/etc/ -type f -exec sed -i "s|"$pkgdir"||g" {} \;
}
