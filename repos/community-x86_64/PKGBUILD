# Maintainer: kpcyrd <kpcyrd[at]archlinux[dot]org>
# Contributor: Jean Lucas <jean@4ray.co>

pkgname=signal-desktop
_pkgname=Signal-Desktop
pkgver=5.40.1
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
sha512sums=('08f652221a6b2be0307ed6dbde94301a858e6894d578fa746a9d324c883feb29fd5de3102a4d44f19dc001a8071ebffd6e19595ebe14ceffe529edb77ac3d9f5'
            '90cfee563a985bc73c4e7984715d190ae0b5c7aa887a7dc15c665980ca5cc8420b02f6c7a54e032c29e18876d5d51cfbe5027a9f0a59de3903f50fd469d73ce0'
            '1154859e87d8a2d649bc23210f2dd8aa473f268166559a51a2a64fe6ae094c101121535623b05b711bd87aab1f219627e9274fa542fdb0e5fe6f34b46fd7b7df')
b2sums=('fbc3f59974a59212bfbab5fe49bd1848ce5dd27c0dcfc9055f9dc4e398f5faffd7e00bf261a754860d2eca8572171da27b5808f2eb64715456adea80a8d32bca'
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
