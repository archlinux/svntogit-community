# Maintainer: Alexander Epaneshnikov <alex19ep@archlinux.org>
# Contributor: libertylocked <libertylocked@disroot.org>

pkgname=bitwarden
pkgver=1.29.0
pkgrel=1
_jslibcommit='764dc40b36e0000807e59b8d6feea5ac4577270d'
_electronversion=14
pkgdesc='A secure and free password manager for all of your devices'
arch=('x86_64')
url='https://github.com/bitwarden/desktop'
license=('GPL3')
depends=("electron$_electronversion" 'libnotify' 'libsecret' 'libxtst' 'libxss' 'libnss_nis')
makedepends=('npm' 'python' 'node-gyp' 'nodejs-lts-fermium' 'jq')
source=(${pkgname}-${pkgver}.tar.gz::https://github.com/bitwarden/desktop/archive/v${pkgver}.tar.gz
        jslib-${_jslibcommit}.tar.gz::https://github.com/bitwarden/jslib/archive/${_jslibcommit}.tar.gz
        package.json.patch
        messaging.main.ts.patch
        ${pkgname}.sh
        ${pkgname}.desktop)
sha512sums=('70323734681fa766390ac00831f371bff3ee023169e27b5348216e9cbf9fbaa8e14d4d689d5d5aa3ffc36b88c0b71b23a90c0cf418f7fc60ac5feae6f8bfea2d'
            '08fcfa6e23e405d1a01238268ae55bef263f91173d1d28ec96e20cdc892229304c0b84dfcb3c722615f8dd6bb46cb9c3fad21ace46da06d4a349e1008e49e559'
            '87cdb8287cbc0c4eb49b0fd456a66e200551b5da5c14991505f6301cf1b11132d938dfdf795c4df2a4b3e1ae2badf5dfe33c1207923ec8abc6f9b3e064af6015'
            '822d97be407c2ac2a6926f5c925b0fd188c541014a623dd3815fdbf5ef67c0542f43aaf8d11535571a83a265f620e330f5326244f42c3902fddab442128fda95'
            '44ee70d71abf9cf399736d00df0aa6815d452792c9589f5517fed4454bdfff6ad2a39ffee401eab0db180718b19e9565d9ecff8d1bd96a93d13e4f63eaf4d5fc'
            '05b771e72f1925f61b710fb67e5709dbfd63855425d2ef146ca3770b050e78cb3933cffc7afb1ad43a1d87867b2c2486660c79fdfc95b3891befdff26c8520fd')

prepare() {
	cd desktop-${pkgver}
	# Link jslib
	rmdir -v jslib
	ln -vs ../jslib-${_jslibcommit} jslib

	# Remove pre and postinstall routines from package.json.
	patch --strip=1 package.json ../package.json.patch
	# This patch is required to make "Start automatically on login" work
	patch --strip=1 src/main/messaging.main.ts ../messaging.main.ts.patch
	# Patch build to make it work with system electron
	export SYSTEM_ELECTRON_VERSION=$(electron$_electronversion -v | sed 's/v//g')
	export ELECTRONVERSION=$_electronversion
	jq < package.json \
	   '.build["electronVersion"]=$ENV.SYSTEM_ELECTRON_VERSION | .build["electronDist"]="/usr/lib/electron\(env.ELECTRONVERSION)"' \
	   > package.json.patched
	mv package.json.patched package.json
}

build() {
	cd desktop-${pkgver}
	electronDist=/usr/lib/electron$_electronversion
	electronVer=$(electron$_electronversion --version | tail -c +2)
	export npm_config_cache="$srcdir/npm_cache"
	export ELECTRON_SKIP_BINARY_DOWNLOAD=1
	pushd jslib
	npm install
	popd
	npm install
	npm run build
	npm run clean:dist
	npm exec -c "electron-builder --linux --x64 --dir -c.electronDist=$electronDist \
	             -c.electronVersion=$electronVer"
}

package(){
	cd desktop-${pkgver}
	install -vDm644 dist/linux-unpacked/resources/app.asar -t "${pkgdir}/usr/lib/${pkgname}"
	install -vDm644 build/package.json -t "${pkgdir}/usr/lib/${pkgname}"

	for i in 16 32 48 64 128 256 512; do
		install -vDm644 resources/icons/${i}x${i}.png "${pkgdir}/usr/share/icons/hicolor/${i}x${i}/apps/${pkgname}.png"
	done
	install -vDm644 resources/icon.png "${pkgdir}/usr/share/icons/hicolor/1024x1024/apps/${pkgname}.png"

	install -vDm755 "${srcdir}/${pkgname}.sh" "${pkgdir}/usr/bin/bitwarden-desktop"
	install -vDm644 "${srcdir}"/${pkgname}.desktop -t "${pkgdir}"/usr/share/applications
}
