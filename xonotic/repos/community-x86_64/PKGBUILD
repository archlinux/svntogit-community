# Maintainer: Sven-Hendrik Haase <sh@lutzhaase.com>
# Contributor: Alexander Suhoverhov <cy at ngs dot ru>
pkgname=xonotic
pkgver=0.5.0
pkgrel=1
pkgdesc="A free, fast-paced crossplatform first-person shooter"
arch=('i686' 'x86_64')
url="http://xonotic.org"
license=('GPL')
depends=('alsa-lib' 'curl' 'libjpeg>=8' 'libmodplug' 'libvorbis' 'libxpm' 'libxxf86dga' 'libxxf86vm' 'sdl' 'libpng>=1.4.0' 'xonotic-data')
makedepends=('unzip' 'mesa')
source=("http://dl.xonotic.org/xonotic-${pkgver}-source.zip"
        "xonotic-glx.desktop"
        "xonotic-sdl.desktop")
md5sums=('7382f195386b8e51df65e57e6be413e5'
         '914c7b9163e92b35f0ab57fdb1653ac5'
         'da7d812ff231c9332cd694b39757adda')

build() {
  # compile Xonotic-flavored fteqcc
  #make -C Xonotic/source/fteqcc

  # compile QuakeC game code
  #( cd Xonotic/source/qcsrc/server && ../../fteqcc/fteqcc.bin -O3 -Ono-c -Ono-cs )
  #( cd Xonotic/source/qcsrc/client && ../../fteqcc/fteqcc.bin -O3 -Ono-c -Ono-cs )
  #( cd Xonotic/source/qcsrc/menu && ../../fteqcc/fteqcc.bin -O3 -Ono-c -Ono-cs )

  # compile engine
	make -C Xonotic/source/darkplaces CPUOPTIMIZATIONS="${CFLAGS}" DP_FS_BASEDIR=/usr/share/xonotic/ DP_LINK_TO_LIBJPEG=1 cl-release
	make -C Xonotic/source/darkplaces CPUOPTIMIZATIONS="${CFLAGS}" DP_FS_BASEDIR=/usr/share/xonotic/ DP_LINK_TO_LIBJPEG=1 sdl-release
	make -C Xonotic/source/darkplaces CPUOPTIMIZATIONS="${CFLAGS}" DP_FS_BASEDIR=/usr/share/xonotic/ DP_LINK_TO_LIBJPEG=1 sv-release
}

package() {
	cd $srcdir/Xonotic

	# binaries
	install -Dm755 source/darkplaces/darkplaces-dedicated $pkgdir/usr/bin/xonotic-dedicated
	install -Dm755 source/darkplaces/darkplaces-glx $pkgdir/usr/bin/xonotic-glx
	install -Dm755 source/darkplaces/darkplaces-sdl $pkgdir/usr/bin/xonotic-sdl

	# convenience files
	mkdir -p $pkgdir/usr/share/applications
	install -Dm644 $srcdir/*.desktop -t $pkgdir/usr/share/applications
	install -Dm644 $srcdir/Xonotic/misc/logos/icons_png/xonotic_512.png $pkgdir/usr/share/pixmaps/xonotic.png
}

# vim: ts=2:sw=2 et:
