#  Maintainer: Loui Chang <louipc dot ist at gmail company>
# Contributor: Sergej Pupykin <pupykin.s+arch@gmail.com>

pkgname=oldstand-font
pkgver=2.2
pkgrel=1
pkgdesc="Old Standard fonts"
url="http://www.thessalonica.org.ru/en/fonts.html"
arch=('any')
license=('OFL')
depends=('xorg-fonts-encodings' 'xorg-fonts-alias' 'xorg-font-utils' 'fontconfig')
makedepends=('unzip')
install=oldstand.install
source=(http://www.thessalonica.org.ru/downloads/oldstandard-$pkgver.otf.zip
	http://www.thessalonica.org.ru/downloads/oldstandard-$pkgver.ttf.zip
	http://www.thessalonica.org.ru/downloads/tempora-lgc.otf.zip
	http://www.thessalonica.org.ru/downloads/tempora-lgc.ttf.zip)
md5sums=('f590bdf4960c36c9c1cbd0a75e06d721'
         'd6b17fd7cb4f7a06db95558696f5bb3e'
         '602808695c1306ff572e7d39cd512ba8'
         '46c5ef4c074583a451ec56336011a12d')

build() {
  cd $startdir/src
  mkdir -p $pkgdir/usr/share/fonts/TTF
  mkdir -p $pkgdir/usr/share/fonts/OTF

  cp *.ttf $pkgdir/usr/share/fonts/TTF || return 1
  cp *.otf $pkgdir/usr/share/fonts/OTF || return 1
  chmod 0644 $pkgdir/usr/share/fonts/OTF/*
  chmod 0644 $pkgdir/usr/share/fonts/TTF/*

  install -D -m0644 $srcdir/OFL.txt \
  $pkgdir/usr/share/licenses/$pkgname/OFL.txt
}
