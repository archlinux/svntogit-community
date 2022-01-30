# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>

pkgname=sequoia-sq
pkgver=0.25.0
pkgrel=2
pkgdesc='Command-line frontends for Sequoia'
url='https://sequoia-pgp.org/'
arch=('x86_64')
license=('GPL2')
groups=('sequoia')
replaces=('sequoia')
depends=('glibc' 'nettle' 'libnettle.so' 'libhogweed.so'
         'bzip2' 'libbz2.so' 'gcc-libs' 'gmp' 'openssl')
makedepends=('git' 'cargo' 'clang')
options=('!lto')
source=(sequoia::"git+https://gitlab.com/sequoia-pgp/sequoia.git#tag=sq/v${pkgver}?signed")
sha512sums=('SKIP')
validpgpkeys=(
  D2F2C5D45BE9FDE6A4EE0AAF31855247603831FD # justus@sequoia-pgp.org
  CBCD8F030588653EEDD7E2659B7DD433F254904A # justus@sequoia-pgp.org
)

prepare() {
  cd sequoia
  # sq: When merging keyrings, produce output in a reproducible order
  git cherry-pick -n 8b0506f8b1570b34ccec908ed4fa3797cbe9222f
}

build() {
  cd sequoia/sq
  export CARGO_TARGET_DIR=../target
  cargo build --release --locked --features 'crypto-nettle compression net autocrypt'
}

check() {
  cd sequoia/sq
  cargo test --release --locked --features 'crypto-nettle compression net autocrypt'
}

package() {
  cd sequoia
  install -Dm 755 target/release/sq -t "${pkgdir}/usr/bin"

	install -Dm 644 target/sq.bash "${pkgdir}/usr/share/bash-completion/completions/sq"
	install -Dm 644 target/_sq -t "${pkgdir}/usr/share/zsh/site-functions"
	install -Dm 644 target/sq.fish -t "${pkgdir}/usr/share/fish/vendor_completions.d"

  install -Dm 644 sq/man-sq-net-autocrypt/*.1 -t "${pkgdir}/usr/share/man/man1"
}

# vim: ts=2 sw=2 et:
