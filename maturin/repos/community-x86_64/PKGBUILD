# Maintainer: David Runge <dvzrv@archlinux.org>

pkgname=maturin
pkgver=0.13.7
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
sha512sums=('509564719aa7b25c1464036b6830518129b24a285075ef551fbb65c42aa2e3c2cfb1bfcefa55cd9b99c7dcec07795ea08fef0a33a55c14030f49afb392face7d')
b2sums=('fef8ad495208109b867d1ca9700cef149b799bdb372d5110480a035ee5ed52b569f5cb3ca7dffa7d69db3fd4a593d3b894027eb1538e25deddd68146640cdde7')

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
