# Maintainer: David Runge <dvzrv@archlinux.org>

pkgname=maturin
pkgver=0.13.3
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
sha512sums=('8a187c126f80137e23e5950dcfde981ce4ab961f838f505b9f038e18bd841324ccdf557a377f39ceed1df7e5934751cc4de3cf36148534fceeee917496a4fb71')
b2sums=('6e6ac88a59b66698a28d01cf485e761e39499abd93f7456b5dce41f444c50eeec9f154268b1e9c092077833259b0141aed7a70829200e7e4390a69675bb805a2')

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
