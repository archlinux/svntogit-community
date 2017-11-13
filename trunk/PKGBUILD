# Maintainer: Jiachen Yang <farseerfc@gmail.com>
# AUR Maintainer: Vlad M. <vlad@archlinux.net>

pkgname=toxic
pkgdesc='CLI Tox client'
license=('GPL3')
pkgver=0.8.0
pkgrel=6
depends=('curl'
         'desktop-file-utils'
         'freealut'
         'libnotify'
         'qrencode'
         'toxcore')
arch=('i686' 'x86_64')
url='https://github.com/JFreegman/toxic'
source=("$pkgname-$pkgver.tar.gz::https://github.com/JFreegman/$pkgname/archive/v$pkgver/$pkgname-$pkgver.tar.gz"
	"$pkgname-$pkgver.tar.gz.asc::https://github.com/JFreegman/$pkgname/releases/download/v$pkgver/$pkgname-$pkgver.tar.gz.asc"
	"ver0.8.0.patch::https://github.com/JFreegman/toxic/commit/c4ace288af92bd416c6b4452ce8a2a179f62db83.patch"
	)
sha512sums=('3c59edb61b1bcdbfa3a8391a1a1ceccc6c9c38b49c1709813d60480b180fb39607806116b9dcd1de35ebb02e23e95d78c8191f04a4875e06e27fa43bc9800b33'
            'SKIP'
            'b9a5cd86eec05965739b40af60e696dc57a3913ed72f605bb4649000ea3418fa6a5e729f5ae26352c86dd21fe6c48ed2ff50c4aab5df51a143e254a8e73bb545')
validpgpkeys=('BABD00573A065BFA90D53D563627F3144076AE63')  # Jfreegman <jfreegman@gmail.com>

prepare() {
  cd "$pkgname-$pkgver"
  patch -Np1 < ../ver0.8.0.patch
}

build() {
  cd "$pkgname-$pkgver"
  # enabled X11 on konsole may cause https://github.com/JFreegman/toxic/issues/277
  # but we can only do video and call with X11 enabled https://bugs.archlinux.org/task/52836
  make PREFIX=/usr
}

package() {
  cd "$pkgname-$pkgver"
  make PREFIX=/usr DESTDIR="$pkgdir" install
}
