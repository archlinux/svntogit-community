# Maintainer: Johannes Löthberg <johannes@kyriasis.com>
# Contributor: Daniel Greve <greve.daniel.l@gmail.com>

pkgname=ttf-roboto
pkgver=2.138
pkgrel=4
pkgdesc="Google's signature family of fonts"
url='https://material.google.com/style/typography.html'
arch=('any')
license=('Apache')
source=(https://sources.archlinux.org/other/community/ttf-roboto/ttf-roboto-hinted-$pkgver.zip)
md5sums=('a7e2d4b06e2137172838f8ef37f89339')

package() {
  install -Dm644 *.ttf -t "$pkgdir"/usr/share/fonts/TTF
}
