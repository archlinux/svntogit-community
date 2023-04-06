# Maintainer: David Runge <dvzrv@archlinux.org>

pkgname=maturin
pkgver=0.14.16
pkgrel=2
pkgdesc="Build and publish crates with pyo3, rust-cpython and cffi bindings"
url="https://github.com/PyO3/maturin"
arch=(x86_64)
license=(Apache)
depends=(
  gcc-libs
  glibc
  rust
)
makedepends=(
  bzip2
  git
)
# disable LTO until ring can be built with it: https://github.com/briansmith/ring/issues/1444
options=(!lto)
source=($url/archive/v$pkgver/$pkgname-v$pkgver.tar.gz)
sha512sums=('8e7e5739b9ff46989011035634c29aa390c60dd5b109f41dcd47bdf6ffb7081bf5ebc160cbae6647baeaa4d3f209167f48ea52ea9b3b676e978617d28bb9c121')
b2sums=('8731fa1ef7ebb6d1645f25ab431cc53d66748a8a54f6d9ea690a09bd753ca15063eeba90296aeac1fd2360feef168c9e64f9ec1b5224e72063c4949a58f876a8')

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
