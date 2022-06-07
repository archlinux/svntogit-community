# Maintainer: David Runge <dvzrv@archlinux.org>

pkgname=maturin
pkgver=0.12.19
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
sha512sums=('782fb0f1715fdae913b34a6fc5eed6b750546903b0d7a522db1280ac8ebaece221c48acc200a4e10687ea8acc5e9b596079e8e8eb990f0a824ef78a5ab41b57a')
b2sums=('16311ca462bb38432156e09a3c15133bbe0dbb9dbdbb390610b1e97d89940dc01c4e4e8e01649baa90e9bede9cbf203b89ab730ee8251c867e26d6e1aff2d053')

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
  install -vDm 644 {Changelog,Readme}.md -t "$pkgdir/usr/share/doc/$pkgname/"
}
