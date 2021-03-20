# Maintainer: Levente Polyak <anthraxx[at]archlinux[dot]org>

_gemname=builder
pkgname=ruby-${_gemname}
pkgver=3.2.4
pkgrel=2
pkgdesc='Provide a simple way to create XML markup and data structures'
url='http://onestepback.org/'
arch=('any')
license=('MIT')
depends=('ruby')
makedepends=('ruby-rdoc' 'ruby-rake')
checkdepends=('ruby-minitest')
options=('!emptydirs')
source=(https://github.com/tenderlove/builder/archive/v${pkgver}/${pkgname}-v${pkgver}.tar.gz
        ruby30.patch::https://github.com/tenderlove/builder/pull/15/commits/6e530dccbb7278bfdc2ee21acf62184ab494fa93.patch)
sha512sums=('0aed47b4f0855510f446f0a500929fe59025e3d178036c627c04c7754f49e1d8f2893b1ec16b881f6f93d364c9e17f281f7a6742c6dd9c4fcd9cec938cbb1684'
            '9dd3ef717786b52fb80d69fb6724bc38f0ddb61e00e4bf1bc6d51e8dda6e8fc39ab990da591cfa59fdeb4d64dd299725040c7d726357045ca28bd8fd588e21e0')
b2sums=('9ff3a96e1c918fb98026ac897f2b7d971249dad9b62936792e2c4bd2e249bc702311bd1ecbd35b0c9e28bc19b720fe26703c220527061fc4c2c57543f8d0568b'
        '71057f8ff6c187a8af81bef93e82dbf14bc6ea9d2f2384941c5cbeacdc31efeccaddcc43b05e80d34e78a8eb5097f4f87414eecab541842d658188e6824fc499')

prepare() {
  cd ${_gemname}-${pkgver}
  patch -p1 < ../ruby30.patch
}

build() {
  cd ${_gemname}-${pkgver}
  rake builder:gem
}

check() {
  cd ${_gemname}-${pkgver}
  rake test
}

package() {
  cd ${_gemname}-${pkgver}
  local _gemdir="$(gem env gemdir)"
  gem install --ignore-dependencies --no-user-install -i "${pkgdir}${_gemdir}" \
    -n "${pkgdir}/usr/bin" pkg/${_gemname}-${pkgver}.gem

  install -Dm 644 README.md CHANGES -t "${pkgdir}/usr/share/doc/${pkgname}"
  install -Dm 644 MIT-LICENSE -t "${pkgdir}/usr/share/licenses/${pkgname}"

  rm -r "${pkgdir}/${_gemdir}/cache"
}

# vim: ts=2 sw=2 et:
