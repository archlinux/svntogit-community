# Maintainer: kpcyrd <kpcyrd[at]archlinux[dot]org>
# Contributor: Jean Lucas <jean@4ray.co>

pkgname=signal-desktop
_pkgname=Signal-Desktop
pkgver=5.11.0
pkgrel=1
pkgdesc="Signal Private Messenger for Linux"
license=('AGPL3')
arch=('x86_64')
url="https://signal.org"
depends=('gtk3' 'libvips' 'libxss' 'hicolor-icon-theme')
makedepends=('yarn' 'git' 'git-lfs' 'nodejs-lts-fermium' 'npm6' 'python')
source=(
  "${pkgname}-${pkgver}.tar.gz::https://github.com/signalapp/${_pkgname}/archive/v${pkgver}.tar.gz"
  "${pkgname}.desktop"
  "expire-from-source-date-epoch.patch"
)
sha512sums=('880a59f77cdc9f88786863328313e3ea7de43f9f3a5619410f79f5a8a18dae4eec735e8b4deddc432c7b66a0d87a1baf136e2a5c579b9b658fb60c213aede122'
            '90cfee563a985bc73c4e7984715d190ae0b5c7aa887a7dc15c665980ca5cc8420b02f6c7a54e032c29e18876d5d51cfbe5027a9f0a59de3903f50fd469d73ce0'
            '6673066172d6c367961f3e2d762dd483e51a9f733d52e27d0569b333ad397375fd41d61b8a414b8c9e8dbba560a6c710678b3d105f8d285cb94d70561368d5a2')
b2sums=('5b6275e18b323931cd71a803af47414a3e75ee443aad299953bd777e420c81702b91f4365f9d4e91d91f886a3d6d347081e5026bf7e7d485dd00a4f7d595c526'
        'b0974f1409bf77e917a3ecce68a9d066eaf24a6cd35e0d52b0d61fcf2fb014f19962bb445b6eaf668081d370c69c01b08420c056902907574a29a71a4f0f2457'
        'b8171e6d881a6ffd5588d1cae00ed81412eff1602670003fc1f48b7e6cb2d680340d464b7b38ee8886a8bd8193166ad71e3ad10b0de8b2a397b383b72434e289')

prepare() {
  cd "${_pkgname}-${pkgver}"

  # git-lfs hook needs to be installed for one of the dependencies
  git lfs install

  # Allow higher Node versions
  sed 's#"node": "#&>=#' -i package.json

  # Select node-gyp versions with python3 support
  sed 's#"node-gyp": "5.0.3"#"node-gyp": "6.1.0"#' -i package.json
  # https://github.com/sass/node-sass/pull/2841
  # https://github.com/sass/node-sass/issues/2716
  sed -r 's#("resolutions": \{)#"resolutions": {"node-sass/node-gyp": "^6.0.0",#' -i package.json

  yarn install --ignore-engines

  # We can't read the release date from git so we use SOURCE_DATE_EPOCH instead
  patch --forward --strip=1 --input="${srcdir}/expire-from-source-date-epoch.patch"
}

build() {
  cd "${_pkgname}-${pkgver}"
  yarn generate
  yarn build
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
