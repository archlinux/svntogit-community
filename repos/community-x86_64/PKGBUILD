# Maintainer: David Runge <dvzrv@archlinux.org>

pkgname=maturin
pkgver=0.14.5
pkgrel=1
pkgdesc="Build and publish crates with pyo3, rust-cpython and cffi bindings"
url="https://github.com/PyO3/maturin"
arch=(x86_64)
license=(Apache)
depends=(gcc-libs glibc rust)
makedepends=(bzip2 git)
# disable LTO until ring can be built with it: https://github.com/briansmith/ring/issues/1444
options=(debug !lto)
source=($pkgname-$pkgver.tar.gz::https://github.com/PyO3/$pkgname/archive/refs/tags/v$pkgver.tar.gz)
sha512sums=('71c35f4dcaf817b158fbbb51dad8a8cfbdfdfce3d8b9ae639e1940d1a9aae0606f130b7129abedf36a913e58e38803136ee69695662bce410286f034a4c83c90')
b2sums=('fee6f179346c47b267b569805e78fd2afa83210b7ea7ca2702fea92c979583661334fef6c0ca5042974014bc8b6be0d8b3b72ba7aa1091005f74f69db56da165')

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
