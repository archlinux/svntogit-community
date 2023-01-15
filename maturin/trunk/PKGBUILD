# Maintainer: David Runge <dvzrv@archlinux.org>

pkgname=maturin
pkgver=0.14.10
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
sha512sums=('8bbeb1ed01adbb0a234e616b4ef2947f20741d7ca17174b0e36cc7bd850d7fc183665b9777933049dd39819cbd8445dd7ddff4ab5c9bb7f87b78ca65bf9cad47')
b2sums=('08213cb43ef9e15a2db1ff02de7f91c6fbb7b5d8c87effef9d0aba3ae7b52c27d70c8fac81e44e694364897a43a6cec2cea4168f7165e0858da6224ef0f3897a')

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
