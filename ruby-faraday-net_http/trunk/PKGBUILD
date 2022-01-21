# Maintainer: Tim Meusel <tim@bastelfreak.de>

_gemname='faraday-net_http'
pkgname="ruby-${_gemname}"
pkgver=2.0.1
pkgrel=1
pkgdesc='Faraday adapter for Net::HTTP'
arch=('any')
url='https://github.com/lostisland/faraday-net_http'
license=('MIT')
depends=('ruby')
makedepends=('ruby-rspec')
checkdepends=('ruby-rspec' 'ruby-faraday' 'ruby-webmock' 'ruby-multipart-parser')
options=('!emptydirs')
source=("${url}/archive/v${pkgver}/${_gemname}-v${pkgver}.tar.gz")
sha512sums=('558d339140e6bc55af595a3070b7869d90ff9a0a9a4bcdbd9b7820cf49be87aea051f4b32fcb51320b2495615073be412ce41b90019593286d8f8b52ff2cc49e')

prepare() {
  cd "${srcdir}/${_gemname}-${pkgver}"

  # drop broken/cirular dependencies
  sed --in-place '/add_development_dependency/d' "${_gemname}.gemspec"
}

build() {
  cd "${srcdir}/${_gemname}-${pkgver}"
  gem build "${_gemname}.gemspec"
}

check() {
  cd "${srcdir}/${_gemname}-${pkgver}"
   rspec
}

package() {
cd "${srcdir}/${_gemname}-${pkgver}"
  local _gemdir="$(gem env gemdir)"
  gem install --verbose --ignore-dependencies --no-user-install --install-dir "${pkgdir}/${_gemdir}" --bindir "${pkgdir}/usr/bin" "${_gemname}-${pkgver}.gem"

  install -Dm 644 LICENSE.md -t "${pkgdir}/usr/share/licenses/${pkgname}/"

  install -Dm 644 README.md CODE_OF_CONDUCT.md -t "${pkgdir}/usr/share/doc/${pkgname}"

  rm -rf "${pkgdir}/${_gemdir}/cache"
}
