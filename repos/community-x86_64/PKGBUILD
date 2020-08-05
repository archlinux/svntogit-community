# Maintainer: kpcyrd <kpcyrd[at]archlinux[dot]org>
# Contributor: Jean Lucas <jean@4ray.co>

pkgname=signal-desktop
_pkgname=Signal-Desktop
pkgver=1.34.5
pkgrel=1
pkgdesc="Signal Private Messenger for Linux"
license=('GPL3')
replaces=('signal-desktop-bin')
arch=('x86_64')
url="https://signal.org"
depends=('libvips')
makedepends=('yarn' 'git' 'nodejs' 'npm' 'python')
source=(
  "${pkgname}-${pkgver}.tar.gz::https://github.com/signalapp/${_pkgname}/archive/v${pkgver}.tar.gz"
  "${pkgname}.desktop"
  "openssl-linking.patch"
  "expire-from-source-date-epoch.patch"
  # Cherry-pick a specific commit for the node-spellchecker dependency
  # See https://github.com/atom/node-spellchecker/issues/127
  "https://github.com/atom/node-spellchecker/archive/613ff91dd2d9a5ee0e86be8a3682beecc4e94887.tar.gz"
)
sha512sums=('07c81b46791ab30e2ffa45f0bceb69dbf5a0029a6fa5da859c75917c012f97ed29154e19797d0ed962249516b9cf4365e54f6997d62c4069305f89eb54a86c01'
            'd07220429c479e3b6aaafede95da117bdb735877162f584265a16434ed75a926c21534e8d291de53e58a1bf0a72cdd41a9a8ae7314e2f6fec98c938852a3b991'
            '6b846fdf70dae6c4657de523ec133d2f08325740863660b86e75d032bb07a4b97834ba0eeea4c77000c2c20b11739b8e8deaf06584f9279638e640c4b7633dd5'
            '6673066172d6c367961f3e2d762dd483e51a9f733d52e27d0569b333ad397375fd41d61b8a414b8c9e8dbba560a6c710678b3d105f8d285cb94d70561368d5a2'
            '42f57802fa91dafb6dbfb5a3f613c4c07df65e97f8da84c9a54292c97a4d170f8455461aac8f6f7819d1ffbea4bf6c28488f8950056ba988776d060be3f107dd')
b2sums=('b2b7303c718ec4ee68af1e6a089837e4fe94e5f0fd3da2f64d3ea628679938f3a74dc2fb3462dcc186f7f792d2ce4759d98a1395ce65b13bdcee0a08e26da8c9'
        'b05d190f28029c65d5cc15f69804db0b2775ff55b4db3a721c1dcf4aa8219b459453740fd26afecb6d72a515366af80af0b985d7b58e542a9edd76bb251ae000'
        '91fe76cd2ef32bd523aa857a219209f93ca5a6a3f5caa35f67c489a8eb79c8e1e404f453bed9e866e543ed48b9df8e17b45ad2ea8891b48d1502a97589a144af'
        'b8171e6d881a6ffd5588d1cae00ed81412eff1602670003fc1f48b7e6cb2d680340d464b7b38ee8886a8bd8193166ad71e3ad10b0de8b2a397b383b72434e289'
        '53ad39f0bed69c5c5635d2e581f4ce56e3080fee16f184add08adee1164c2d68059d52071478a05cdacf04186f9964250f46f09e80553bf35e1f2f4cd1976d1b')

prepare() {
  cd "${_pkgname}-${pkgver}"

  # Fix SpellChecker build with imminent Node 13
  # See https://github.com/atom/node-spellchecker/issues/127
  sed -r 's#("spellchecker": ").*"#\1file:'"${srcdir}"'/613ff91dd2d9a5ee0e86be8a3682beecc4e94887.tar.gz"#' -i package.json

  # Allow higher Node versions
  sed 's#"node": "#&>=#' -i package.json

  # Select node-gyp versions with python3 support
  sed 's#"node-gyp": "5.0.3"#"node-gyp": "6.1.0"#' -i package.json
  # https://github.com/sass/node-sass/pull/2841
  # https://github.com/sass/node-sass/issues/2716
  sed 's#"resolutions": {#"resolutions": {"node-sass/node-gyp": "^6.0.0",#' -i package.json

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
