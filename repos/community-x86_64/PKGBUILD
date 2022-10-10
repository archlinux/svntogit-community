# Maintainer: David Runge <dvzrv@archlinux.org>

pkgname=maturin
pkgver=0.13.6
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
sha512sums=('bf5d2b9de8671d540ef02ab63bb76ade143a5b75fd93f492cdf21aa7f4e9ac53c3e027f74c75f674d35dd8fe3a21d3f1cd6ff857227664d30a9ad3b336b10761')
b2sums=('d761632cf761e688d4807e38de1879023c113701add7ca3474a7791d7c1194b52c4a8163d32961602f42505c94de64ec8633c400ce1e5350f151f14a07a90977')

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
