# Maintainer: David Runge <dvzrv@archlinux.org>

pkgname=maturin
pkgver=0.13.0
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
sha512sums=('836c9e7450a7203db59391876ea52a7fe7c64e3803beb49a5152832aaafee6dd7ce7e6d751772c9ccbb075f5cc7b7299719c7ebf63a0d2abd27070b78268efd8')
b2sums=('6e6be3f69dcf95724cbeca1e816b6d28bdaddcaa118064386cf270e5b44ec9772aa324104d00614b68df35d6e7e2f161652ebe4f6019270c7d949394acfff447')

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
