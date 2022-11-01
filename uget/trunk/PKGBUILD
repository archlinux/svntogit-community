# Maintainer: Balló György <ballogyor+arch at gmail dot com>

pkgname=uget
pkgver=2.2.3
pkgrel=6
pkgdesc='GTK download manager featuring download classification and HTML import'
arch=('x86_64')
url='https://ugetdm.com/'
license=('LGPL')
depends=('libnotify' 'gtk3' 'gstreamer' 'curl')
makedepends=('intltool')
optdepends=('aria2: alternative backend')
source=("https://downloads.sourceforge.net/urlget/$pkgname-$pkgver-1.tar.gz"
        'gcc10.patch'
        'disable-rss.patch'
        'uget-gtk.appdata.xml')
sha256sums=('11356e4242151b9014fa6209c1f0360b699b72ef8ab47dbeb81cc23be7db9049'
            'f1f5cd7fbe57387178e107d4672d2b4550fe5f5200fc6ab139b6ee43ccf87093'
            '8c4d97fff4f58a44c62e07c627fd09d868aa6801cff8775a9b8da83250175e1c'
            'd6c341ef4c21b1312586e2342725be172507d128246a9ad88b2e8ef142140a5a')

prepare() {
  cd $pkgname-$pkgver

  # Fix build with GCC 10
  patch -Np1 -i ../gcc10.patch

  # Disable checking nonexistent RSS feeds
  patch -Np1 -i ../disable-rss.patch

  # Don't force x11 backend (FS#70837)
  sed -i 's/env GDK_BACKEND=x11 uget-gtk/uget-gtk/' uget-gtk.desktop
}

build() {
  cd $pkgname-$pkgver
  ./configure --prefix=/usr --disable-rss-notify
  make
}

package() {
  cd $pkgname-$pkgver
  make DESTDIR="$pkgdir" install
  install -Dm644 ../uget-gtk.appdata.xml "$pkgdir/usr/share/metainfo/uget-gtk.appdata.xml"
}
