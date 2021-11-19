# Maintainer: David Runge <dvzrv@archlinux.org>

pkgname=maturin
pkgver=0.12.0
pkgrel=1
pkgdesc="Build and publish crates with pyo3, rust-cpython and cffi bindings"
url="https://github.com/PyO3/maturin"
arch=(x86_64)
license=(Apache)
depends=(gcc-libs glibc rust)
makedepends=(bzip2 dbus git)
source=(${pkgname}-${pkgver}.tar.gz::https://github.com/PyO3/${pkgname}/archive/refs/tags/v${pkgver}.tar.gz)
sha512sums=('93255d425922b8c4fd7145391368d0aa8cdb1e88d5a148a65ee2d843dc38e327f776bb42d32e4163183274803ffd560710343afea0aa89bbab7e98a9aa28d6b5')
b2sums=('9dcb841e7455943a76de6a4fd769a0b4779730141383f83ccf51dd24172803ecb8122b7dde9477b85bbcfc9d6149a4391531fbd49aa6015eeee407f25cb526e6')

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
