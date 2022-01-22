# Maintainer: Andreas 'Segaja' Schleifer <segaja at archlinux dot org>

_gemname='websocket-extensions'
pkgname="ruby-${_gemname}"
pkgver=0.1.5
pkgrel=2
pkgdesc='Generic extension manager for WebSocket connections'
arch=('any')
url='https://github.com/faye/websocket-extensions-ruby'
license=('Apache')
options=(!emptydirs)
depends=('ruby')
checkdepends=('ruby-bundler' 'ruby-rspec')
source=("${url}/archive/${pkgver}/${pkgname}-${pkgver}.tar.gz")
sha512sums=('a80154d0c83743ffa4dd3eee1adcc93bb38907fbae4260602a91c922e5a022806413a8aa84dc10bc14b5ed2ca928765ef4c39e04ff0a0c5f9b423aff2b2514fd')

prepare() {
  cd "${_gemname}-ruby-${pkgver}"

  # update gemspec/Gemfile to allow newer version of the dependencies
  sed --in-place --regexp-extended 's|~>|>=|g' "${_gemname}.gemspec"
}

build() {
  cd "${_gemname}-ruby-${pkgver}"

  gem build "${_gemname}.gemspec"
}

check() {
  cd "${_gemname}-ruby-${pkgver}"

  bundle exec rspec
}

package() {
  cd "${_gemname}-ruby-${pkgver}"

  local _gemdir="$(gem env gemdir)"

  gem install --ignore-dependencies --no-user-install -i "${pkgdir}/${_gemdir}" -n "${pkgdir}/usr/bin" "${_gemname}-${pkgver}.gem"

  rm "${pkgdir}/${_gemdir}/cache/${_gemname}-${pkgver}.gem"

  install -Dm 644 CHANGELOG.md CODE_OF_CONDUCT.md README.md --target-directory "${pkgdir}/usr/share/doc/${pkgname}"
}
