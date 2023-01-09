# Maintainer: Caleb Maclennan <caleb@alerque.com>
# Contributor: Daniel Peukert <daniel@peukert.cc>

pkgname=age-plugin-yubikey
pkgver=0.3.2
pkgrel=1
pkgdesc='Yubikey plugin for age'
arch=(x86_64 i686 arm armv6h armv7h aarch64)
url="https://github.com/str4d/$pkgname"
license=(Apache MIT)
depends=(pcsclite)
makedepends=(cargo)
optdepends=('age: for use with age'
            'rust-rage: for use with rage')
_archive="$pkgname-$pkgver"
source=("$url/archive/v$pkgver/$_archive.tar.gz")
sha256sums=('1c160403ff982e172207eb5975803b00acfaf30dd89b902f0b1eed53d8400f6c')

prepare() {
	cd "$_archive"
	cargo fetch --locked --target "$CARCH-unknown-linux-gnu"
}

build() {
	cd "$_archive"
	cargo build --frozen --release --all-features
}

check() {
	cd "$_archive"
	cargo test --frozen --all-features
}

package() {
	cd "$_archive"
	install -Dm0755 -t "$pkgdir/usr/bin/" "target/release/$pkgname"
	install -Dm0644 -t "$pkgdir/usr/share/licenses/$pkgname/" LICENSE-MIT
}
