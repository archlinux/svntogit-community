# Maintainer: David Runge <dvzrv@archlinux.org>

pkgname=maturin
pkgver=0.12.16
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
sha512sums=('e568836e04296523c0bf8b673d1ce67103a34a6fb8c5d73f7aab3e58a883fc0daaffa730b2e2e1849bbad9f59f080ac1aaa4a0da7f4acd2439fd359e8ed755c5')
b2sums=('401107c57d2919683f4cd21579354e89d7916a3f723130d40d1e8e9aea606e4d9e0ac133e1d2a863367ebe93473c89429839d37ddf012a5139734f7cf6597c1e')

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
  install -vDm 755 target/release/maturin -t "$pkgdir/usr/bin/"
  install -vDm 644 {Changelog,Readme}.md -t "$pkgdir/usr/share/doc/$pkgname/"
}
