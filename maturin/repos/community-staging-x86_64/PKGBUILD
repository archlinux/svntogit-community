# Maintainer: David Runge <dvzrv@archlinux.org>

pkgname=maturin
pkgver=0.14.17
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
sha512sums=('d12503530b0d865b6b3c40e564742d0e798107102fb7167c137c1b0a4fa63bfad739320901cff15a680a09034aae553c3cd55cf0c8f1d3ed0fd96404bb93cbfe')
b2sums=('4d0d2d5101a05017883b27dca270c3f3b84c77dd53f19db04c2b5a988b699f3b39b6b7a88c7ac02b5e322679f5509bdf68b5c5f27ec229816c394ebc5fb57fd8')

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
