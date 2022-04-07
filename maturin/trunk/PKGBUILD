# Maintainer: David Runge <dvzrv@archlinux.org>

pkgname=maturin
pkgver=0.12.12
pkgrel=1
pkgdesc="Build and publish crates with pyo3, rust-cpython and cffi bindings"
url="https://github.com/PyO3/maturin"
arch=(x86_64)
license=(Apache)
depends=(gcc-libs glibc rust)
makedepends=(bzip2 dbus git)
# disable LTO until ring can be built with it: https://github.com/briansmith/ring/issues/1444
options=(!lto)
source=($pkgname-$pkgver.tar.gz::https://github.com/PyO3/$pkgname/archive/refs/tags/v$pkgver.tar.gz)
sha512sums=('bcadb9fb6fc9b4aa6bf7ae5c8ce52f725e8664068ee8405cc235433a6fc5b6a7c18fd57fefa6453779be54137c8549e041c903670bc6c5fa8411ca8774c7870a')
b2sums=('4c0b6e37304aceb7b30397218647eb574e91226fec8bccfbf6d6ef3d2658c57bc572653750cede5f82c52595ff5aacf470d2cc044d262ae3f1d801823d5a8869')

prepare() {
  cd $pkgname-$pkgver
  cargo fetch --locked --target "$CARCH-unknown-linux-gnu"
}

build() {
  cd $pkgname-$pkgver
  cargo build --frozen --release --all-features
}

package() {
  depends+=(libbz2.so libdbus-1.so)

  cd $pkgname-$pkgver
  install -vDm 755 target/release/maturin -t "$pkgdir/usr/bin"
  install -vDm 644 {Changelog,Readme}.md -t "$pkgdir/usr/share/doc/$pkgname"
}
