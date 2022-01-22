# Maintainer: Andreas 'Segaja' Schleifer <segaja at archlinux dot org>

_gemname='websocket-driver'
pkgname="ruby-${_gemname}"
pkgver=0.7.5
pkgrel=2
pkgdesc='WebSocket protocol handler with pluggable I/O'
arch=('x86_64')
url='https://github.com/faye/websocket-driver-ruby'
license=('Apache')
options=(!emptydirs)
depends=('ruby' 'ruby-websocket-extensions')
makedepends=('ruby-rake' 'ruby-rake-compiler')
checkdepends=('ruby-bundler' 'ruby-eventmachine' 'ruby-permessage_deflate' 'ruby-rspec')
source=("${url}/archive/${pkgver}/${pkgname}-${pkgver}.tar.gz")
sha512sums=('538c78cd39507fb6cddeaa6196f0e2bbb89d7293f062d9b0231b6c6988a46b718c91b69a50b4cbf5b227067e6ed4ee89c61759bf340fc3e483c4af97052d42f9')

prepare() {
  cd "${_gemname}-ruby-${pkgver}"

  # update gemspec/Gemfile to allow newer version of the dependencies
  sed --in-place --regexp-extended 's|~>|>=|g' "${_gemname}.gemspec"
}

build() {
  cd "${_gemname}-ruby-${pkgver}"

  rake gem
}

check() {
  cd "${_gemname}-ruby-${pkgver}"

  bundle exec rspec
}

package() {
  cd "${_gemname}-ruby-${pkgver}"

  local _gemdir="$(gem env gemdir)"
  local _platform="$(gem env platform | cut -d':' -f2)"
  local _extension_api_version="$(ruby -e'puts Gem.extension_api_version')"

  gem install --ignore-dependencies --no-user-install -i "${pkgdir}/${_gemdir}" -n "${pkgdir}/usr/bin" "pkg/${_gemname}-${pkgver}.gem"

  rm "${pkgdir}/${_gemdir}/cache/${_gemname}-${pkgver}.gem" \
      "${pkgdir}/${_gemdir}/gems/${_gemname}-${pkgver}/ext/websocket-driver/Makefile" \
      "${pkgdir}/${_gemdir}/extensions/${_platform}/${_extension_api_version}/${_gemname}-${pkgver}/gem_make.out"
  rm -rf "${pkgdir}/${_gemdir}/doc/${_gemname}-${pkgver}/ri/ext/"

  install -Dm 644 CHANGELOG.md CODE_OF_CONDUCT.md README.md --target-directory "${pkgdir}/usr/share/doc/${pkgname}"
}
