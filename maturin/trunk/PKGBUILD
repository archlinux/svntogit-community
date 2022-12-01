# Maintainer: David Runge <dvzrv@archlinux.org>

pkgname=maturin
pkgver=0.14.3
pkgrel=1
pkgdesc="Build and publish crates with pyo3, rust-cpython and cffi bindings"
url="https://github.com/PyO3/maturin"
arch=(x86_64)
license=(Apache)
depends=(gcc-libs glibc rust)
makedepends=(bzip2 git)
# disable LTO until ring can be built with it: https://github.com/briansmith/ring/issues/1444
options=(!lto)
source=($pkgname-$pkgver.tar.gz::https://github.com/PyO3/$pkgname/archive/refs/tags/v$pkgver.tar.gz)
sha512sums=('6a2d8cf0284e0cd4a118be0ec3c7e02baf9852881b12558f78a3c91a88e8fdd2a873ad69449254d3ce5166f6033871d214c08b5f3e6edbd632a6fa2c2501ecb4')
b2sums=('c787ad0311c4a497f53615bd19e6ec9f37c5acd20ac0dedc5c18a12011ae7191e5ca3b9c0fa2f94c405260ea2805c7c1c32e0453f1c21beaa719d66079083539')

prepare() {
  cd $pkgname-$pkgver
  cargo fetch --locked --target "$CARCH-unknown-linux-gnu"
}

build() {
  cd $pkgname-$pkgver
  cargo build --frozen --release --all-features
}

package() {
  depends+=(libbz2.so)

  cd $pkgname-$pkgver
  install -vDm 755 target/release/maturin -t "$pkgdir/usr/bin/"
  install -vDm 644 {Changelog,README}.md -t "$pkgdir/usr/share/doc/$pkgname/"
}
