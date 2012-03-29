# Maintainer:  Bartłomiej Piotrowski <barthalion@gmail.com>
# Contributor: Thomas Dziedzic < gostrc at gmail >
# Contributor: Bert Muennich <muennich at informatik.hu-berlin.de>
# Contributor: Brad Fanella <bradfanella@archlinux.us>

pkgname=sxiv
pkgver=1.0
pkgrel=4
pkgdesc='simple x image viewer'
arch=('x86_64' 'i686')
license=('GPL2')
install=sxiv.install
url='https://github.com/muennich/sxiv'
depends=('libx11' 'xproto' 'imlib2' 'giflib' 'libexif' 'desktop-file-utils')
makedepends=('gendesk>=0.3')
source=("https://github.com/downloads/muennich/sxiv/$pkgname-$pkgver.tar.gz"
	'config.h')
md5sums=('c887e0af1e4d5a101b285a46d288c419'
         'c3e6c4b86da6b17687699dbd32c7717b')
_genericname=('Image viewer')
_mimetype=('image/bmp;image/gif;image/jpeg;image/jpg;image/png;image/tiff;image/x-bmp;')

build() {
  cd "$srcdir"
  gendesk

  cd "sxiv-$pkgver"
  cp "$srcdir/config.h" .
  make
}

package() {
  cd "$pkgname-$pkgver"

  make PREFIX="$pkgdir/usr" install
  install -Dm644 "$srcdir/$pkgname.png" \
    "$pkgdir/usr/share/pixmaps/$pkgname.png"
  install -Dm644 "$srcdir/$pkgname.desktop" \
    "$pkgdir/usr/share/applications/$pkgname.desktop"
}

# vim:set ts=2 sw=2 et:
