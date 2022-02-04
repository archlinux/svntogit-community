# Maintainer: Caleb Maclennan <caleb@alerque.com>
# Maintainer: Bruno Pagani <archange at archlinux dot org>
# Contributor: William Gathoye <william + aur at gathoye dot be>
# Contributor: Aleksandar Trifunović <akstrfn at gmail dot com>
# Contributor: Jan Was <janek dot jan at gmail dot com>
# Contributor: AUR[Severus]

pkgname=mattermost-desktop
pkgver=5.0.3
pkgrel=2
pkgdesc='Mattermost Desktop application'
arch=(x86_64)
url="https://github.com/${pkgname/-//}"
license=(Apache)
_electron=electron14
_builderVersion='^22.14.5'
depends=($_electron)
makedepends=(git
             gendesk
             jq
             moreutils
             npm)
_archive="${pkgname#*-}-$pkgver"
source=("$pkgname-$pkgver.tar.gz::$url/archive/v$pkgver.tar.gz"
        "$pkgname.sh")
sha256sums=('cf73a7cec26b99b044911e1a366966eb9c7cb14cc82bd83b13b1ab15d41b3902'
            '1c2bf48b6397d04a5a536c5c9f4960db53249c838c380f03f808c612b00ba4c6')

_npmargs="--cache '$srcdir/npm-cache' --no-audit --no-fund"

prepare() {
	gendesk -q -f -n \
		--pkgname "$pkgname" \
		--pkgdesc "$pkgdesc" \
		--name Mattermost \
		--categories 'Network;InstantMessaging;' \
		--mimetypes 'x-scheme-handler/mattermost;' \
		--custom StartupWMClass="$pkgname"
	cd "$_archive"
	sed -i -e "s/git rev-parse --short HEAD/echo $pkgver/" webpack.config.base.js
	sed -e "s/@ELECTRON@/$_electron/" "../$pkgname.sh" > "$pkgname.sh"
	sed -i -e 's#resources/linux#src/assets/linux#' electron-builder.json
	sed -i -e 's/--ia32//g;s/--mac//g;s/--arm64//g;s/--win//g;s/--universal//g' package.json
	local electronDist="/usr/lib/$_electron"
	local electronVersion="$(<"$electronDist"/version)"
	# Do not build tar.gz, nor .deb or appimages
	# Use electron version that matches system package
	jq '
				.linux .target |= ["dir"] |
				{
					"electronDist": $electronDist,
					"electronVersion": $electronVersion
				} + .
			' \
			--arg electronDist "$electronDist" \
			--arg electronVersion "$electronVersion" \
			electron-builder.json |
		sponge electron-builder.json
	jq '
				del(.devDependencies["electron"]) |
				.devDependencies["electron-builder"] = $builderVersion
			' \
			--arg electronVersion "$electronVersion" \
			--arg builderVersion "$_builderVersion" \
			package.json |
		sponge package.json
	npm $_npmargs install
}

build() {
	cd "$_archive"
	npm $_npmargs --offline run package:linux
}

package() {
	cd "$_archive"
	install -Dm0644 -t "$pkgdir/usr/lib/$pkgname/" release/linux*unpacked/resources/app.asar
	install -Dm0644 -t "$pkgdir/usr/share/licenses/$pkgname/" LICENSE.txt
	install -Dm0644 src/assets/linux/icon.svg "$pkgdir/usr/share/icons/hicolor/scalable/apps/$pkgname.svg"
	install -Dm0755 "$pkgname.sh" "$pkgdir/usr/bin/$pkgname"
	install -Dm0644 -t "$pkgdir/usr/share/applications/" "../$pkgname.desktop"
}
