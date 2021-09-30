# Maintainer: Lukas Fleischer <lfleischer@archlinux.org>
# Maintainer: Daniel M. Capella <polyzen@archlinux.org>
# Contributor: Ronald van Haren <ronald.archlinux.org>
# Contributor: Roman Kyrylych <Roman.Kyrylych@gmail.com>
# Contributor: Andreas Zwinkau
# Contributor: rabyte <rabyte__gmail>
# Contributor: Stefan Husmann < stefan-husmann@t-online.de>

pkgname=ttf-liberation
pkgver=2.1.5
pkgrel=1
pkgdesc='Font family which aims at metric compatibility with Arial, Times New Roman, and Courier New'
arch=('any')
url=https://github.com/liberationfonts/liberation-fonts
license=('custom:OFL')
makedepends=('fontforge' 'python-fonttools')
provides=('ttf-font')
source=("$url/archive/$pkgver/liberation-fonts-$pkgver.tar.gz")
b2sums=('8e8ed55456823c61dc8c622a9674c540770abc944ce87bd96ae64a8f13b450e5386335e9f24723344a9e7f882b8e323f4a43231b4659c117c5b7670027f42199')

build() {
  cd liberation-fonts-$pkgver
  make build
}

package() {
  cd liberation-fonts-$pkgver
  install -Dm644 -t "$pkgdir/usr/share/fonts/${pkgname#ttf-}" \
    liberation-fonts-ttf-$pkgver/*.ttf
  install -Dm644 -t "$pkgdir/usr/share/licenses/$pkgname" LICENSE
}
