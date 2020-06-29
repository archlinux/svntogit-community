# Maintainer: Daniel M. Capella <polyzen@archlinux.org>
# Contributor: Gaetan Bisson <bisson@archlinux.org>
# Contributor: Damir Perisa <damir.perisa@bluewin.ch>
# Contributor: Firmicus <francois.archlinux.org> 

pkgname=ttf-indic-otf
pkgver=0.2
pkgrel=11
pkgdesc='Indic Opentype Fonts collection'
url=https://indlinux.org/wiki/index.php/Downloads
license=('GPL')
arch=('any')
source=("https://indlinux.org/downloads/files/indic-otf-$pkgver.tar.gz")
sha512sums=('ecb85ca38b40b0afd23c57a5529e3a5eec175852d28d5f9e49592e53f91530ff63737e86df3fe574daf725a673eb59c1ec653b25c7a67642bbfe378df7964bfb')

package() {
  cd indic/OpenType
  install -Dm644 -t "$pkgdir"/usr/share/fonts/TTF *.ttf
}

# vim:set ts=2 sw=2 et:
