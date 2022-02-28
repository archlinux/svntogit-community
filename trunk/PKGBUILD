# Maintainer: Alexander Epaneshnikov <alex19ep@archlinux.org>
# Contributor: libertylocked <libertylocked@disroot.org>

pkgname=bitwarden
pkgver=1.31.3
pkgrel=2
_electronversion=16
pkgdesc='A secure and free password manager for all of your devices'
arch=('x86_64')
url='https://github.com/bitwarden/desktop'
license=('GPL3')
depends=("electron$_electronversion" 'libnotify' 'libsecret' 'libxtst' 'libxss' 'libnss_nis')
makedepends=('git' 'npm' 'python' 'node-gyp' 'nodejs-lts-gallium' 'jq')
source=(${pkgname}::git+https://github.com/bitwarden/desktop.git#tag=v$pkgver
        bitwarden-jslib::git+https://github.com/bitwarden/jslib.git
        messaging.main.ts.patch
        ${pkgname}.sh
        ${pkgname}.desktop)
sha512sums=('SKIP'
            'SKIP'
            'babcae0dba4d036e5d2cd04d8932b63253bc7b27b14d090932066e9d39383f7565c06d72dae9f96e741b494ef7e50a1fe7ec33905aa3124b427a8bf404df5762'
            '98d2860bef2283fd09710fbbc5362d7ef2cd8eca26f35805ea258f2dacba78bd6aab14c834388a5089a8150eb0f32a82577aab10f8ad68e1a6371959b2802ad4'
            '05b771e72f1925f61b710fb67e5709dbfd63855425d2ef146ca3770b050e78cb3933cffc7afb1ad43a1d87867b2c2486660c79fdfc95b3891befdff26c8520fd')

prepare() {
	cd bitwarden
	# Link jslib
	git submodule init
	git config submodule.jslib.url "$srcdir/bitwarden-jslib"
	git submodule update

	# This patch is required to make "Start automatically on login" work
	patch --strip=1 src/main/messaging.main.ts ../messaging.main.ts.patch
	# Patch build to make it work with system electron
	export SYSTEM_ELECTRON_VERSION=$(electron$_electronversion -v | sed 's/v//g')
	export ELECTRONVERSION=$_electronversion
	sed -i "s|@electronversion@|${ELECTRONVERSION}|" ../bitwarden.sh
	jq < package.json \
	   '.build["electronVersion"]=$ENV.SYSTEM_ELECTRON_VERSION | .build["electronDist"]="/usr/lib/electron\(env.ELECTRONVERSION)"' \
	   > package.json.patched
	mv package.json.patched package.json
}

build() {
	cd bitwarden
	electronDist=/usr/lib/electron$_electronversion
	electronVer=$(electron$_electronversion --version | tail -c +2)
	export npm_config_cache="$srcdir/npm_cache"
	export ELECTRON_SKIP_BINARY_DOWNLOAD=1
	npm install --build-from-source
	npm run build
	npm run clean:dist 
	npm exec -c "electron-builder --linux --x64 --dir -c.electronDist=$electronDist \
	             -c.electronVersion=$electronVer"
}

package(){
	cd bitwarden
	install -vDm644 dist/linux-unpacked/resources/app.asar -t "${pkgdir}/usr/lib/${pkgname}"
	install -vDm644 build/package.json -t "${pkgdir}/usr/lib/${pkgname}"
	cp -vr dist/linux-unpacked/resources/app.asar.unpacked -t "${pkgdir}/usr/lib/${pkgname}"

	for i in 16 32 48 64 128 256 512; do
		install -vDm644 resources/icons/${i}x${i}.png "${pkgdir}/usr/share/icons/hicolor/${i}x${i}/apps/${pkgname}.png"
	done
	install -vDm644 resources/icon.png "${pkgdir}/usr/share/icons/hicolor/1024x1024/apps/${pkgname}.png"

	install -vDm755 "${srcdir}/${pkgname}.sh" "${pkgdir}/usr/bin/bitwarden-desktop"
	install -vDm644 "${srcdir}"/${pkgname}.desktop -t "${pkgdir}"/usr/share/applications
}
