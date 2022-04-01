# Maintainer: kpcyrd <kpcyrd[at]archlinux[dot]org>
# Contributor: Jean Lucas <jean@4ray.co>

pkgname=signal-desktop
_pkgname=Signal-Desktop
pkgver=5.37.0
pkgrel=1
pkgdesc="Signal Private Messenger for Linux"
license=('AGPL3')
arch=('x86_64')
url="https://signal.org"
depends=('gtk3' 'libvips' 'libxss' 'hicolor-icon-theme')
makedepends=('yarn' 'git' 'git-lfs' 'nodejs-lts-gallium' 'npm' 'python' 'libxcrypt-compat')
source=(
  "${pkgname}-${pkgver}.tar.gz::https://github.com/signalapp/${_pkgname}/archive/v${pkgver}.tar.gz"
  "${pkgname}.desktop"
  "expire-from-source-date-epoch.patch"
)
sha512sums=('03acff9172e7e2bc0efa0d50805e30b542cc4c6aea6acec24095c4dba6b10f3f2c2d166bc4b2694bbd1545318fdcd1de1d65ffd19cc1f68207a2df6b9a704a9d'
            '90cfee563a985bc73c4e7984715d190ae0b5c7aa887a7dc15c665980ca5cc8420b02f6c7a54e032c29e18876d5d51cfbe5027a9f0a59de3903f50fd469d73ce0'
            '1154859e87d8a2d649bc23210f2dd8aa473f268166559a51a2a64fe6ae094c101121535623b05b711bd87aab1f219627e9274fa542fdb0e5fe6f34b46fd7b7df')
b2sums=('15b4a9076171b0fa9dd6f8220bbbb7df13f8381b726a343d7ec255f024e68d2408829a5447b3bf5f48bdeb0e7bace54938bce06c7d8f917d177b46242055a46b'
        'b0974f1409bf77e917a3ecce68a9d066eaf24a6cd35e0d52b0d61fcf2fb014f19962bb445b6eaf668081d370c69c01b08420c056902907574a29a71a4f0f2457'
        '5a6dba4bfa799403ace721b143c5b54d3bff97ab0c3d30e94d312cf58ede2498886720247b0efcbbeffc0c95611a493625cef1f8bc06d3647b53ef2e44de96be')

prepare() {
  cd "${_pkgname}-${pkgver}"

  # git-lfs hook needs to be installed for one of the dependencies
  git lfs install

  # Allow higher Node versions
  sed 's#"node": "#&>=#' -i package.json

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
