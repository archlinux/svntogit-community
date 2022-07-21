# Maintainer: kpcyrd <kpcyrd[at]archlinux[dot]org>
# Contributor: Jean Lucas <jean@4ray.co>

pkgname=signal-desktop
_pkgname=Signal-Desktop
pkgver=5.51.0
pkgrel=1
pkgdesc="Signal Private Messenger for Linux"
license=('AGPL3')
arch=('x86_64')
url="https://signal.org"
depends=('gtk3' 'libvips' 'libxss' 'hicolor-icon-theme' 'alsa-lib')
makedepends=('yarn' 'git' 'git-lfs' 'nodejs-lts-gallium' 'npm' 'python' 'libxcrypt-compat')
source=(
  "${pkgname}-${pkgver}.tar.gz::https://github.com/signalapp/${_pkgname}/archive/v${pkgver}.tar.gz"
  "${pkgname}.desktop"
  "expire-from-source-date-epoch.patch"
)
sha512sums=('34165dcdd35fbbaa3dd3cf0a3825938aae53ef96f6bd859922f352eb8b597de344f09f24e9d56d94fe760a054ba4ec3d446067efa9565cc7ee2b7d901e3e3102'
            '90cfee563a985bc73c4e7984715d190ae0b5c7aa887a7dc15c665980ca5cc8420b02f6c7a54e032c29e18876d5d51cfbe5027a9f0a59de3903f50fd469d73ce0'
            '1154859e87d8a2d649bc23210f2dd8aa473f268166559a51a2a64fe6ae094c101121535623b05b711bd87aab1f219627e9274fa542fdb0e5fe6f34b46fd7b7df')
b2sums=('d4135a19d5bca27d196435be86eb41c27b03edb11b6a9c8268ead87636e845704269badf391ec6c8f75e5c0aac5251e4abaf58dc3196233d1fbe1b1c1c8a2d77'
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
