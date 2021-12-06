# Maintainer: David Runge <dvzrv@archlinux.org>

pkgname=maturin
pkgver=0.12.4
pkgrel=2
pkgdesc="Build and publish crates with pyo3, rust-cpython and cffi bindings"
url="https://github.com/PyO3/maturin"
arch=(x86_64)
license=(Apache)
depends=(gcc-libs glibc rust)
makedepends=(bzip2 dbus git)
source=(${pkgname}-${pkgver}.tar.gz::https://github.com/PyO3/${pkgname}/archive/refs/tags/v${pkgver}.tar.gz)
sha512sums=('fff317651501f142586826692adf1152dd82bd3d8a5aade337edf1f688a1c12ecb13a5ac1978c23f1c798ea140d5dc87ae3cc68ed73974a52dac3ff30ee1d031')
b2sums=('422eec4148114dbcca7f8a9a8c60c872ba67df330ffa96972abc5481f593e17770e01c08adae2f763424b09f7172701d94d598a57ef068a599b4a6df38288a50')

prepare() {
  cd ${pkgname}-${pkgver}
  cargo fetch --locked --target "$CARCH-unknown-linux-gnu"
}

build() {
  cd ${pkgname}-${pkgver}
  cargo build --frozen --release --all-features
}

package() {
  depends+=(libbz2.so libdbus-1.so)

  cd ${pkgname}-${pkgver}
  install -vDm 755 target/release/maturin -t "${pkgdir}/usr/bin"
  install -vDm 644 {Changelog,Readme}.md -t "${pkgdir}/usr/share/doc/${pkgname}"
}
