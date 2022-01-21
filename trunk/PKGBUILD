# Maintainer: Caleb Maclennan <caleb@alerque.com>
# Contributor: Eli Schwartz <eschwartz@archlinux.org>
# Contributor: Felix Yan <felixonmars@archlinux.org>
# Contributor: Michael Hansen <zrax0111 gmail com>

pkgbase=keybase
pkgname=(keybase kbfs keybase-gui)
pkgdesc='CLI tool for GPG with keybase.io'
pkgver=5.9.1
pkgrel=1
arch=('x86_64')
url=https://keybase.io
_url=https://github.com/keybase/client
license=(BSD)
# git is needed for yarn...
makedepends=(git
             go
             yarn)
_archive="$pkgbase-v$pkgver"
source=("$_url/releases/download/v$pkgver/$_archive.tar.xz"{,.sig}
        "keybase-gui"
        "0001-Maintain-current-contextIsolation-behavior-across-el.patch"
        "0001-Don-t-use-electron-to-build.patch")
sha512sums=('260b3c89a6834ef6285cdc746bcf582ef9376ef06f50fc410a61a002591a5dc1189270ddd4df8516bf24a3c8aa9c6c230339eefe42a5010acf8d4fbdfc551a93'
            'SKIP'
            'bdecad57f8703eb6011b0c9ff238b9f3d78192031adfb5a27a7e6910119c600726b87aaacada88877eaeddcd6134fbe72b014bcaeb6cc7563c3753fcb33c52c9'
            '5cb3d93c4bb468fd47e1670f73cc3b8be14977ccf563a47d776285b6b9d96042647062427e58bd981727362caa23d17acdc0152dfd915efeeb6c4e76ca76ca65'
            '3d38410574ac9d3a09a9ed4ba82bffb3078b15986d8447fe53d7499f538f5c54093f0893667ee64ddd22609b83a8c9c15e50f11f61ddb48cff3ecdf5b8c4628e')
b2sums=('0711762ed70c9977a92702c33e4cddc3eee5b5c7ee4bbc381ae07649b5cc635a811331b6492f853813b82e557bb4211677523e62f68d2e37267957bcafb9d844'
        'SKIP'
        '1ecf08e4a0b2836828fc4f9283a69e1fbda6f268195ae56433050d54070038aacf1ae3057202324c678b242c88345cc8f453c7798129753f083c33db256517a4'
        '67f416c59b549606d037167c796c5b99f0ca9158fb767d52c101f41db6d31927b57618efb4d6eaf590cbd3c7aab4dd71a64bc3b52580e2383f5389c95264a499'
        'd556694526d973431012c36891d82578aeafdd159e7f7f9108325946e874cef4303dff8dc12f0ec7d2c5b731d5cf20bec26c7f18b6483d8f2910c93e3a1a7a68')
validpgpkeys=('222B85B0F90BE2D24CFEB93F47484E50656D16C7') # Keybase.io Code Signing (v1) <code@keybase.io>

prepare() {
	ln -sf "${_archive/$pkgbase/client}" "$_archive"
	cd "$_archive"

	export GOPATH="${srcdir}/.gopath"
	mkdir -p "${GOPATH}"/src/github.com/keybase
	ln -sf "${PWD}" "${GOPATH}"/src/github.com/keybase/client

	# Fix paths to run electron /path/to/app (or our minimal wrapper script).
	# Also wire up "hideWindow" when running as a service or via XDG autostart.
	sed -i 's@/opt/keybase/Keybase@/usr/bin/electron13 /usr/share/keybase-app@' \
		packaging/linux/systemd/keybase.gui.service
	sed -i 's/run_keybase/keybase-gui/g' \
		packaging/linux/keybase.desktop go/install/install_unix.go

	patch -p1 -i ../0001-Don-t-use-electron-to-build.patch
	# New versions of electron tighten sandboxing and applications need to adapt.
	# Keybase did not, so loosen this back to pre v12 levels
	# https://github.com/keybase/client/pull/24551
	patch -p1 -i ../0001-Maintain-current-contextIsolation-behavior-across-el.patch

	cd go
	go mod tidy
}

build() {
	cd "$_archive/go"

	# None of this should be necessary, but we duplicate the work of
	# makepkg.conf here since golang CGO can't be bothered to respect
	# standardized CFLAGS and we don't have native packaging integration for
	# either this or the go-specific flags. Must be done here to make sure
	# we're using debug or !buildflags.

	export CGO_CPPFLAGS="${CPPFLAGS}"
	export CGO_CFLAGS="${CFLAGS}"
	export CGO_CXXFLAGS="${CXXFLAGS}"
	export CGO_LDFLAGS="${LDFLAGS}"
	export GOFLAGS="-buildmode=pie -trimpath -ldflags=-linkmode=external -mod=readonly -modcacherw"

	export GOPATH="${srcdir}/.gopath"
	go build -a -tags production -o ./bin/keybase github.com/keybase/client/go/keybase
	go build -a -tags production -o ./bin/kbnm github.com/keybase/client/go/kbnm
	go build -a -tags production -o ./bin/kbfsfuse github.com/keybase/client/go/kbfs/kbfsfuse
	go build -a -tags production -o ./bin/git-remote-keybase github.com/keybase/client/go/kbfs/kbfsgit/git-remote-keybase

	cd ../shared
	yarn install
	yarn run package --appVersion $pkgver
}

package_keybase() {
	depends=('gnupg')
	optdepends=('kbfs: for the fuse-based fileystem and the encryption subcommand')

	cd "$_archive"

	install -Dm755 -t "${pkgdir}"/usr/bin/ go/bin/{keybase,kbnm}

	# native messaging whitelists
	KBNM_INSTALL_ROOT=1 KBNM_INSTALL_OVERLAY="${pkgdir}" "${pkgdir}/usr/bin/kbnm" install
	# systemd activation
	install -Dm644 packaging/linux/systemd/keybase.service "${pkgdir}"/usr/lib/systemd/user/keybase.service
	install -Dm644 LICENSE "${pkgdir}"/usr/share/licenses/${pkgname}/LICENSE
}

package_kbfs() {
	pkgdesc="The Keybase filesystem"
	url="https://keybase.io/docs/kbfs"
	depends=('fuse' 'keybase')
	install=kbfs.install

	cd "$_archive"

	install -Dm755 -t "${pkgdir}"/usr/bin/ go/bin/{kbfsfuse,git-remote-keybase}
	install -Dm644 LICENSE "$pkgdir"/usr/share/licenses/$pkgname/LICENSE
	# more systemd activation
	install -Dm644 packaging/linux/systemd/kbfs.service "$pkgdir"/usr/lib/systemd/user/kbfs.service
}

package_keybase-gui() {
	pkgdesc="GUI frontend for GPG with keybase.io"
	depends=('electron13' 'keybase' 'kbfs')

	cd "$_archive"

	install -Dm644 packaging/linux/x-saltpack.xml \
		"${pkgdir}"/usr/share/mime/packages/x-saltpack.xml
	install -Dm644 packaging/linux/keybase.desktop \
		"${pkgdir}"/usr/share/applications/keybase.desktop
	# more systemd activation
	install -Dm644 packaging/linux/systemd/keybase.gui.service \
		"${pkgdir}"/usr/lib/systemd/user/keybase.gui.service
	# wrapper for electron
	install -Dm755 "${srcdir}"/keybase-gui "${pkgdir}"/usr/bin/keybase-gui

	install -Dm644 LICENSE "${pkgdir}"/usr/share/licenses/${pkgname}/LICENSE

	for i in 16 32 128 256 512 ; do
		install -Dm644 media/icons/Keybase.iconset/icon_${i}x${i}.png \
			"${pkgdir}"/usr/share/icons/hicolor/${i}x${i}/apps/keybase.png
		install -Dm644 media/icons/Saltpack.iconset/icon_${i}x${i}.png \
			"${pkgdir}"/usr/share/icons/hicolor/${i}x${i}/mimetypes/application-x-saltpack.png
	done
	# ???
	install -Dm644 media/icons/Keybase.iconset/icon_32x32@2x.png \
		"${pkgdir}"/usr/share/icons/hicolor/64x64/apps/keybase.png
	install -Dm644 media/icons/Keybase.iconset/icon_512x512@2x.png \
		"${pkgdir}"/usr/share/icons/hicolor/1024x1024/apps/keybase.png

	# the app itself
	cd shared/desktop/build
	rm -rf desktop/sourcemaps/
	mkdir -p "${pkgdir}"/usr/share/keybase-app
	cp -r * "${pkgdir}"/usr/share/keybase-app/
}
