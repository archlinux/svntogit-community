# Maintainer: kpcyrd <kpcyrd[at]archlinux[dot]org>

pkgname=auth-tarball-from-git
pkgver=0.2.0
pkgrel=1
pkgdesc='Authenticate a tarball through a signed tag in a git repository (with reproducible builds)'
url='https://github.com/kpcyrd/auth-tarball-from-git'
arch=('x86_64')
license=('GPL3')
depends=('git' 'sequoia-sqv')
makedepends=('cargo')
source=(https://github.com/kpcyrd/${pkgname}/archive/v${pkgver}/${pkgname}-${pkgver}.tar.gz
        https://github.com/kpcyrd/${pkgname}/releases/download/v${pkgver}/${pkgname}-${pkgver}.tar.gz.asc)
b2sums=('811e9970e3fd7f577465dfe840ed53d00ec1eb1d1c5369f2d3cdb73dd4cb956bf291874f925b2b05f704b1ee532bc63b6a6ebb988ae593e6f754325f148992d8'
        'SKIP')

validpgpkeys=("64B13F7117D6E07D661BBCE0FE763A64F5E54FD6")


prepare() {
  cd "${pkgname}-${pkgver}"
  cargo fetch --locked --target "$CARCH-unknown-linux-gnu"
}

build() {
  cd ${pkgname}-${pkgver}
  cargo build --frozen --release
}

check() {
  cd ${pkgname}-${pkgver}
  cargo test --frozen --release
}

package() {
  cd ${pkgname}-${pkgver}
  install -Dm 755 target/release/${pkgname} -t "${pkgdir}/usr/bin"
}

# vim: ts=2 sw=2 et:
