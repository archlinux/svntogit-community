# Maintainer: Andreas 'Segaja' Schleifer <segaja at archlinux dot org>

_gemname='permessage_deflate'
pkgname="ruby-${_gemname}"
pkgver=0.1.4
pkgrel=1
pkgdesc='Per-message DEFLATE compression extension for WebSocket connections'
arch=('any')
url='https://github.com/faye/permessage-deflate-ruby'
license=('Apache')
options=(!emptydirs)
depends=('ruby')
checkdepends=('ruby-bundler' 'ruby-rspec')
source=("${url}/archive/${pkgver}/${pkgname}-${pkgver}.tar.gz")
sha512sums=('9e8e9af7cf7d13d05420ebe773e1bef4212174d82d87f9e4a2cac96dee197666cff60ffbc3f0744d3dbd2ae59b07a90bbbffa513632aafb38a0ba2b01ec6e471')

prepare() {
  cd "${_gemname/_/-}-ruby-${pkgver}"

  # update gemspec/Gemfile to allow newer version of the dependencies
  sed --in-place --regexp-extended 's|~>|>=|g' "${_gemname}.gemspec"
}

build() {
  cd "${_gemname/_/-}-ruby-${pkgver}"

  gem build "${_gemname}.gemspec"
}

check() {
  cd "${_gemname/_/-}-ruby-${pkgver}"

  bundle exec rspec
}

package() {
  cd "${_gemname/_/-}-ruby-${pkgver}"

  local _gemdir="$(gem env gemdir)"

  gem install --ignore-dependencies --no-user-install -i "${pkgdir}/${_gemdir}" -n "${pkgdir}/usr/bin" "${_gemname}-${pkgver}.gem"

  rm "${pkgdir}/${_gemdir}/cache/${_gemname}-${pkgver}.gem"

  install -Dm 644 LICENSE.md "${pkgdir}/usr/share/licenses/${pkgname}/LICENSE"
  install -Dm 644 CHANGELOG.md CODE_OF_CONDUCT.md README.md --target-directory "${pkgdir}/usr/share/doc/${pkgname}"
}
