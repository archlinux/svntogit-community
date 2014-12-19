# Maintainer: Antonio Rojas <arojas@archlinux.org>
# Contributor: Stefan Husmann <stefan-husmann@t-online.de>
# Contributor: thacrazze <thacrazze|googlemail|com>

pkgname=clipgrab
pkgver=3.4.8
pkgrel=1
pkgdesc='A video downloader and converter for YouTube, Veoh, DailyMotion, MyVideo, ...'
arch=('i686' 'x86_64')
url='http://clipgrab.de/en'
license=('GPL3')
depends=('qtwebkit')
optdepends=('ffmpeg: for the conversion functionality')
source=(http://download.clipgrab.de/$pkgname-$pkgver.tar.bz2
        $pkgname.desktop)
md5sums=('f15acc189a2bbf43fd0ed3a47e1d9ee0'
         '9a141791f6952917c441050c3dac81ce')

build() {
  cd $pkgname

  qmake-qt4 clipgrab.pro
  make
}

package() {
  cd $pkgname
  install -Dm755 $pkgname "$pkgdir/usr/bin/$pkgname"
  install -Dm644 icon.png "$pkgdir/usr/share/pixmaps/$pkgname.png"
  install -Dm644 "$srcdir/$pkgname.desktop" "$pkgdir/usr/share/applications/$pkgname.desktop"
}
