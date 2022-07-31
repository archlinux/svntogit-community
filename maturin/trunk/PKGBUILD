# Maintainer: David Runge <dvzrv@archlinux.org>

pkgname=maturin
pkgver=0.13.1
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
sha512sums=('e1958cce932b8da7a11c31ec3dda91d187568b31bb306afc4adf46dafc22d23576fd1018fd889abde52f2bb492aab7a393aa0cf0552722bf0a0dcabca0ac759b')
b2sums=('d554d6fac430acb9300f66065cbe7a6fb22c8384cc4c9ac26b575de7ffb3581e5ed8ca0c90228816eeffb990ad4d79e11e31a152347c69cb5844bc16aa123cb8')

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
