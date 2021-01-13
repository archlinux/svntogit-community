# Maintainer: kpcyrd <kpcyrd[at]archlinux[dot]org>
# Contributor: Jean Lucas <jean@4ray.co>

pkgname=signal-desktop
_pkgname=Signal-Desktop
pkgver=1.39.5
pkgrel=1
pkgdesc="Signal Private Messenger for Linux"
license=('GPL3')
replaces=('signal-desktop-bin')
arch=('x86_64')
url="https://signal.org"
depends=('libvips' 'libxss' 'hicolor-icon-theme')
makedepends=('yarn' 'git' 'nodejs' 'npm' 'python')
source=(
  "${pkgname}-${pkgver}.tar.gz::https://github.com/signalapp/${_pkgname}/archive/v${pkgver}.tar.gz"
  "${pkgname}.desktop"
  "openssl-linking.patch"
  "expire-from-source-date-epoch.patch"
)
sha512sums=('39c0823d55470e39508d03af05c5723283b2843c59d0538498732682895aad02de0199f99bcdf315151af1b5a2292b1e803d7088b77ddc802b8b6967256ef900'
            'd07220429c479e3b6aaafede95da117bdb735877162f584265a16434ed75a926c21534e8d291de53e58a1bf0a72cdd41a9a8ae7314e2f6fec98c938852a3b991'
            '6b846fdf70dae6c4657de523ec133d2f08325740863660b86e75d032bb07a4b97834ba0eeea4c77000c2c20b11739b8e8deaf06584f9279638e640c4b7633dd5'
            '6673066172d6c367961f3e2d762dd483e51a9f733d52e27d0569b333ad397375fd41d61b8a414b8c9e8dbba560a6c710678b3d105f8d285cb94d70561368d5a2')
b2sums=('8682a105bd92e4e3465442273a54ded3dd7cef3fd79f782c4017b1a94e43544ce7a354ef65f35188b56492a2c55fc43280d24c5491dfe194ffb2c46cf9e093c9'
        'b05d190f28029c65d5cc15f69804db0b2775ff55b4db3a721c1dcf4aa8219b459453740fd26afecb6d72a515366af80af0b985d7b58e542a9edd76bb251ae000'
        '91fe76cd2ef32bd523aa857a219209f93ca5a6a3f5caa35f67c489a8eb79c8e1e404f453bed9e866e543ed48b9df8e17b45ad2ea8891b48d1502a97589a144af'
        'b8171e6d881a6ffd5588d1cae00ed81412eff1602670003fc1f48b7e6cb2d680340d464b7b38ee8886a8bd8193166ad71e3ad10b0de8b2a397b383b72434e289')

prepare() {
  cd "${_pkgname}-${pkgver}"

  # Allow higher Node versions
  sed 's#"node": "#&>=#' -i package.json

  # Select node-gyp versions with python3 support
  sed 's#"node-gyp": "5.0.3"#"node-gyp": "6.1.0"#' -i package.json
  # https://github.com/sass/node-sass/pull/2841
  # https://github.com/sass/node-sass/issues/2716
  sed -r 's#("resolutions": \{)#"resolutions": {"node-sass/node-gyp": "^6.0.0",#' -i package.json

  yarn install --ignore-engines

  # Have SQLCipher dynamically link from OpenSSL
  # See https://github.com/signalapp/Signal-Desktop/issues/2634
  patch --forward --strip=1 --input="${srcdir}/openssl-linking.patch"

  # We can't read the release date from git so we use SOURCE_DATE_EPOCH instead
  patch --forward --strip=1 --input="${srcdir}/expire-from-source-date-epoch.patch"
}

build() {
  cd "${_pkgname}-${pkgver}"

  # Gruntfile expects Git commit information which we don't have in a tarball download
  # See https://github.com/signalapp/Signal-Desktop/issues/2376
  yarn generate exec:build-protobuf exec:transpile concat copy:deps sass

  yarn build-release --dir
}

package() {
  cd "${_pkgname}-${pkgver}"

  install -d "${pkgdir}/usr/"{lib,bin}
  cp -a release/linux-unpacked "${pkgdir}/usr/lib/${pkgname}"
  ln -s "/usr/lib/${pkgname}/${pkgname}" "${pkgdir}/usr/bin/"

  chmod u+s "${pkgdir}/usr/lib/signal-desktop/chrome-sandbox"

  install -Dm 644 "../${pkgname}.desktop" -t "${pkgdir}/usr/share/applications"
  for i in 16 24 32 48 64 128 256 512 1024; do
    install -Dm 644 "build/icons/png/${i}x${i}.png" \
      "${pkgdir}/usr/share/icons/hicolor/${i}x${i}/apps/${pkgname}.png"
  done
}

# vim: ts=2 sw=2 et:
